/*

c++ SL

(81)

*/

#include <iostream>
#include <memory>   // for shared_ptr
#include <vector>
#include <string>   // for std::string
#include <fstream>  // for ofstream
#include <cstdio>   // for std::remove(filename)
#include <sys/fcntl.h> // for what?
#include <sys/mman.h>   // for shared memory in Unix header file.. fk
#include <cstring>  // for strerror()
#include <cerrno>   // for errno

class FileDeleter
{
    std::string m_filename;
public:
    FileDeleter(const std::string& fn)
    : m_filename(fn){}

    void operator()(std::ofstream* fp)
    {
        fp->close();                    // close file
        std::remove(m_filename.c_str());  // delete file
    }
};

class SharedMemoryDetacher
{
public:
    void operator()(int* p)
    {
        std::cout << "unlink /tmp1234" << std::endl;
        if(shm_unlink("/tmp1234") != 0 )
        {
            std::cerr << "OOPS: shm_unlink() failed" << std::endl;
        }
    }
};

std::shared_ptr<int> getSharedIntMemory(int num)
{
    void* mem;
    int shmfd = shm_open("/tmp1234", O_CREAT|O_RDWR, S_IRWXU|S_IRWXG);
    if(shmfd < 0)
    {
        throw std::string(std::strerror(std::errno));
    }
    if(ftruncate(shmfd, num*sizeof(int)) == -1)
    {
        throw std::string(std::strerror(errno));
    }
    mem = mmap(nullptr, num*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if(mem == MAP_FAILED)
    {
        throw std::string(std::strerror(errno));
    }

    return std::shared_ptr<int>(static_cast<int*>(mem),
                                SharedMemoryDetacher());
    // or using lambda
    // note: passed deleter is not allowed to throw exceptions
    // thus, we only write an error message to std::cerr here

    return std::shared_ptr<int>(static_cast<int*>(mem),
                                [](int* p)
                                {
                                    std::cout << "unlink /tmp1234" << std::endl;
                                    if(shm_unlink("/tmp1234") != 0)
                                    {
                                        std::cerr << "OOPS: shm_unlink() failed" << std::endl;
                                    }
                                    ...;
                                });
}

int main()
{
    // shared_ptr<T> var(new T(val), optional deleter);
    {
        /*
            using class shared_ptr

        + create:
            using std::shared_ptr<T> p_name(new T(val));
            using std::make_shared();

        + reset():


        + use_count():

        + defining a Deleter:
            passing an anonymous function as second arg

        + dealing with array
            the default deleter provided by shared_ptr calls delete, not delete[]
            in this case, u have to provide your own deleter.
            using lambda function;
            using std::default_delete<T[]>();

        + difference between shared_ptr deleter and unique_ptr deleter
            - unique_ptr provide the ability to own an array simply by passing the correspond element type as template arg
            - unique_ptr requires u to specify a second template arg to specify your own deleter.
            - unique_ptr supports operator []. while shared_ptr provides only (*shared_ptr) and (shared_ptr->), pointer arithmetic and operator[] are not supported
            * the reason this difference is that unique_ptr is optimized for performance and flexibility

        */

        // create shared_ptr
        std::shared_ptr<std::string> p1(new std::string("nico"));
        std::shared_ptr<std::string> p2(new std::string("jutta"));

        // capitalize
        (*p1)[0] = 'N';
        p2->replace(0, 1, "J");

        // put into container
        std::vector<std::shared_ptr<std::string>> v;
        v.push_back(p2);
        v.push_back(p2);
        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p1);

        // iterate over the container
        for(auto p: v)
        {
            std::cout << *p << " ";
        }
        std::cout << std::endl;

        // overwrite a name again
        *p1 = "Nicolai";

        // iterator over the container again
        for(auto p: v)
        {
            std::cout << *p << " ";
        }
        std::cout << std::endl;

        // print something
        std::cout << "use_count: " << v[0].use_count() << std::endl;
    }

    // defining a Deleter
    {
        std::shared_ptr<std::string> p1(new std::string("nico"),
                                        [](std::string* p)
                                        {
                                            std::cout << "delete " << *p << std::endl;
                                            delete p;
                                        });
        std::shared_ptr<std::string> p2(new std::string("julai"),
                                        [](std::string* p)
                                        {
                                            std::cout << "delete " << *p << std::endl;
                                            delete p;
                                        });
        // put into a container
        std::vector<std::shared_ptr<std::string>> v2;
        v2.push_back(p2);
        v2.push_back(p2);
        v2.push_back(p1);
        v2.push_back(p2);
        v2.push_back(p1);
        // or
        p1 = nullptr; // only null ptr thou using copy assignment constructor
        // or
        v2.resize(2);
        // p1 should be deleted

        std::cout << p2.use_count() << std::endl;

    }

    // dealing with array
    {
        std::shared_ptr<int> p1(new int[10]); // error, but compiles
        // if u use new[], u have to define your own deleter
        std::shared_ptr<int> p2(new int[10],
                               [](int* p)
                               {
                                   delete[] p;
                               });
        // or use a helper officially provided for unique_ptr
        std::shared_ptr<int> p3(new int[10],
                                std::default_delete<int[]>());
        // but, note that shared_ptr and unique_ptr deal with deleter in slightly different ways.
        // for example, unique_ptr provides the ability to own an array simply by passing the correspond element type as template args,
        // whereas for shared_ptr this is not possible:
        std::unique_ptr<int[]> p4(new int[10]); // OK
        // std::shared_ptr<int[]> p5(new int[10]); // not OK

        // in addition, for unique_ptr, u have to specify a second template arg to specify your deleter
        std::unique_ptr<int, void(*)(int*)> p6(new int[10],
                                               [](int* p)
                                               {
                                                   delete[] p;
                                               });
    }

    // dealing with other destructor policies
    {
        std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"),
                                          FileDeleter("tmpfile.txt"));
    }

    // dealing with shared memory
    {
        // get and attach shared memory for 100 integers
        std::shared_ptr<int> smp(getSharedIntMemory(100));
        // init the shared memory
        for(int i=0; i<100; ++i)
            smp.get()[i] = i * 42;

        // deal with shared memory somewhere else:
        ...;

        std::cout << "<return>" << std::endl;
        std::cin.get();

        // release
        smp.reset();

        ...;
    }


    return 0;
}
