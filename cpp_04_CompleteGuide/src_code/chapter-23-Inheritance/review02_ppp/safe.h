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
        void setTopSecret(int h) { topSecret = h; }
        void setSecret(int h)    { secret = h; }
    public:
        int noSecret;
        Safe()
        {
            topSecret = 1;
            secret = 2;
            noSecret = 3;
        }
};

class Castle: public Safe
{
    public:
        Castle()
        {
            setTopSecret(3); // private member
            secret = 1;      // protected member
            noSecret = 2;    // public member
        }
        void test(void)
        {
            setTopSecret(300);
            secret = 100;
            noSecret = 200;
        }
};

#endif // SAFE_H_INCLUDED
