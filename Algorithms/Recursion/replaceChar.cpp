#include<vector>
#include<iostream>
#include<string>

void replace(std::string &data, char val, char repl, int i = 0)
{
    if (data[i] == '\0')
        return;
    if (data[i] == val) {
        data[i] = repl;
    }
    replace(data, val, repl, ++i);
}

void remove(std::string& data, char val,int i=0)
{
    if (data[i] == '\0')
        return;
    if (data[i] != val)
        remove(data, val,++i);
    else{
        int j=i;
        while(data[j]!='\0')
        {
            data[j]=data[j+1];
            j++;
        }
    remove(data, val,i);
    }
}

void removeA(char data[],char val)
{
    if(data[0]=='\0')
        return;
    if(data[0]!=val)
        removeA(data+1,val);
    else
    {
        for(int i=0;data[i]!='\0';i++)
        {
            data[i]=data[i+1];
        }
        removeA(data,val);
    }
    
}
int main()
{
    char pali[] = "Anomaly";
    std::string stringPali = "markram";
    std::string stringPali2 = "SAAS";
    char val = 'a';
    char replacer = 'x';

    replace(stringPali, val, replacer);
    std::cout << stringPali << std::endl;

    remove(stringPali, replacer);
    std::cout << stringPali << std::endl;

    removeA(pali,val);
    std::cout << pali << std::endl;

    return 0;
}