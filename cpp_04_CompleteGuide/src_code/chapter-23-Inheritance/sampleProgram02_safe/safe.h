#ifndef SAFE_H_INCLUDED
#define SAFE_H_INCLUDED

class Safe
{
    private:
        int topSecret;
    protected:
        int secret;
        // getter
        int getTopSecret(void) const { return topSecret; }
        int getSecret(void)    const { return secret; }
        // setter
        void setTopSecret(int n) { topSecret = n; }
        void setSecret(int n)    { secret = n; }
    public:
        int noSecret;
        Safe()
        { topSecret=100; secret = 10; noSecret = 0; }
};

class Castle : public Safe
{
    public:
        Castle()
        {
            //topSecret = 10; //Error
            setTopSecret(10);
            secret = 1;
            noSecret = 0;
        }
        void test()
        {
          // top.Secret = 200; // Error
          setTopSecret(200);
          secret = 20;
          noSecret = 2;
        }
};

#endif // SAFE_H_INCLUDED
