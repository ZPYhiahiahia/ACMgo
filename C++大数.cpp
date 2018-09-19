#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define MAXN 5005
#define Max(a,b) (a>b?a:b)
using namespace std;
struct Bign
{
    int len,s[MAXN];
    Bign()
    {
        memset(s,0,sizeof(s));
        len=1;
    }
    Bign(int num){*this=num;}
    Bign(const char *num){*this=num;}
    void clean(){while(len>1&&!s[len-1])len--;} 
    Bign operator = (const int num)
    {
        char s[MAXN];
        sprintf(s,"%d",num);
        *this=s;
        return *this;
    }
    Bign operator = (const char *num)
    {
        len=strlen(num);
        for(int i=0;i<len;i++)s[i]=num[len-i-1]-'0';
        return *this;
    }
    Bign operator + (const Bign& b) 
    {
        Bign c;
        c.len=0;
        for(int i=0,g=0;g||i<Max(len,b.len);i++)
        {
            int x=g;
            if(i<b.len)x+=b.s[i];
            if(i<len)x+=s[i];
            c.s[c.len++]=x%10;
            g=x/10;
        }
        return c;
    }
    Bign operator - (const Bign& b)
    {
        Bign c;
        c.len=0;
        for(int i=0,g=0;i<len;i++)
        {
            int x=s[i]-g;
            if(i<b.len)x-=b.s[i];
            if(x>=0)g=0;
            else{g=1;x+=10;}
            c.s[c.len++]=x;
        }
        c.clean();
        return c;
    }
    Bign operator * (const Bign& b)
    {
        Bign c;
        c.len=len+b.len;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<b.len;j++)
            {
                c.s[i+j]+=s[i]*b.s[j];
            }
        }
        for(int i=0;i<c.len;i++)
        {
            c.s[i+1]+=c.s[i]/10;
            c.s[i]%=10;
        }
        c.clean();
        return c;
    }
    Bign operator * (const int& b)
    {
        Bign c;
        c.len=0;
        for(int i=0,g=0;g||i<len;i++)
        {
            int x;
            if(i<len)x=s[i]*b+g;
            else x=g;
            c.s[c.len++]=x%10;
            g=x/10;
        }
        return c;
    }
    Bign operator / (const Bign& b)
    {
        Bign c,f=0;
        for(int i=len-1;i>=0;i--)
        {
            f=f*10;
            f.s[0]=s[i];
            while(f>=b)
            {
                f=f-b;
                c.s[i]++;
            }
        }
        c.len=len;
        c.clean();
        return c;
    }
    Bign operator / (const int& b)
    {
        Bign c,d=*this;
        c.len=len;
        for(int i=len-1,g=0;i>=0;i--)
        {
            d.s[i]+=g*10;
            c.s[i]=d.s[i]/b;
            g=d.s[i]%b;
        }
        c.clean();
        return c;
    }
    Bign operator % (const Bign& b)
    {
        Bign c=*this/b;
        c=*this-c*b;
        return c;
     } 
    Bign operator += (const Bign& b)
    {*this=*this+b;return *this;}
    Bign operator -= (const Bign& b)
    {*this=*this-b;return *this;}
    Bign operator *= (const Bign& b)
    {*this=*this*b;return *this;}
    Bign operator /= (const Bign& b)
    {*this=*this/b;return *this;}
    Bign operator *= (const int& b)
    {*this=*this*b;return *this;}
    Bign operator /= (const int& b)
    {*this=*this/b;return *this;}
    Bign operator %= (const Bign& b)
    {*this=*this%b;return *this;}
    bool operator < (const Bign& b)
    {
        if(b.len!=len)return len<b.len;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]!=b.s[i])return s[i]<b.s[i];
        }
        return 0;
    }
    bool operator > (const Bign& b)
    {
        if(b.len!=len)return len>b.len;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]!=b.s[i])return s[i]>b.s[i];
        }
        return 0;
    }
    bool operator == (const Bign& b)
    {return !(*this>b)&&!(*this<b);}
    bool operator <= (const Bign& b)
    {return !(*this>b);}
    bool operator >= (const Bign& b)
    {return !(*this<b);}
    bool operator != (const Bign& b)
    {return !(*this==b);}
    string str() const 
    {
        string res;
        for(int i=0;i<len;i++)
        res=char(s[i]+'0')+res; 
        return res;
    }
};
//cin ¶ÁÈë 
istream& operator >> (istream&in,Bign &x)
{
    string s;
    in>>s;
    x=s.c_str();
    return in;
 }
ostream& operator << (ostream&out,Bign x)
{
    out<<x.str();
    return out;
}

int main()
{
    Bign a,b;
    cin>>a>>b;
    cout<<a%b<<endl; 
    return 0;
}
