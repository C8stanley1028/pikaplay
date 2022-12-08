#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString
{
  private:
    string name = "";
    string chars = "";
    size_t len = 0;
    char* strTransChar;
    // something else...
  public:
    MyString();
    MyString(char* c);
    MyString(string s);
    MyString(string s1, string s2);
    ~MyString();
    MyString(const MyString& m);
    char& operator[](int i);
    MyString operator+(const MyString& s2);
    

    friend void assignObject(MyString* [], string*, string*, int, int);
    friend int findAppointedIndex(MyString* [], string*, int, int);
    friend void declareString(MyString* [], string*, string*, int, int);
    friend void assignString(MyString* [], string*, string*, int, int);
    friend void print(MyString* [], string*, int, int);

    const MyString operator*(int j);
    const MyString& operator=(const MyString& m);
    const MyString& operator=(const string& s);
    const MyString& operator=(const char* c);
    const string getStr();
    const string getName();
};

MyString::MyString()
{
    name = "";
    chars = "";
    len = 0;
}
MyString::MyString(char* c)
{  
    for (int x = 0; x < sizeof(*c) / sizeof(char); x++)
    {
        name = name + c[x];
        chars = chars + c[x];
    }
    len = strlen(c);
    strTransChar = new char[strlen(c)+1];
    for(int i = 0; i < strlen(c); i++)
    {
        strTransChar[i] = c[i];
    }
}
MyString::MyString(string s)
{ 
    name = s;
    chars = s;
    len = s.length();
    strTransChar = new char[s.length() + 1];
    strcpy(strTransChar, s.c_str());
}
MyString::MyString(string s1, string s2)
{  
    name = s1;
    chars = s2;
    len = s2.length();
    strTransChar = new char[s2.length() + 1];
    strcpy(strTransChar, s2.c_str());
}
MyString::MyString(const MyString& m)
{
    name = m.name;
    chars = m.chars;
    len = m.len;
    strTransChar = new char[m.len + 1];
    for(int i = 0; i < strlen(m.strTransChar); i++){
        strTransChar[i] = m.strTransChar[i];
    }
}
MyString::~MyString()
{
    delete [] strTransChar;
}

const string MyString::getStr()
{
    return chars;
}
const string MyString::getName()
{
    return name;
}
char& MyString::operator[](int i)
{
    return this->strTransChar[i];
}
const MyString MyString::operator*(int j)
{
    string str = "";
    string str1 = this->chars;
    return 0;
}
MyString MyString::operator+(const MyString& s2)
{
    string str = this->chars + s2.chars;
    const MyString res(this->name, str);
    return 0;
}

const MyString& MyString::operator=(const MyString& m)
{
    chars = m.chars;
    len = m.len;
    delete [] strTransChar;
    strTransChar = new char[m.len + 1];
    for(int i = 0; i < strlen(m.strTransChar); i++){
        strTransChar[i] = m.strTransChar[i];
    }
    return *this;
}
const MyString& MyString::operator=(const string& s)
{
    chars = s;
    len = s.length();
    delete [] strTransChar;
    strTransChar = new char[s.length() + 1];
    strcpy(strTransChar, s.c_str());
    
    return *this;
}
const MyString& MyString::operator=(const char* c)
{
    int arrSize = sizeof(*c)/sizeof(char);
    string str = "";
    for (int x = 0; x < arrSize; x++) {
        str =  str + c[x];
    }
    chars = str;
    len = str.length();
    delete [] strTransChar;
    strTransChar = new char[str.length() + 1];
    strcpy(strTransChar, str.c_str());
    
    return *this;
}

void declareString(MyString* [], string*, string*, int, int);
void print(MyString* [], string*, int, int);
int findAppointedIndex(MyString* [], string*, int, int);
void assignString(MyString* [], string*, string*, int, int);
void assignObject(MyString* [], string*, string*, int, int);

int main() 
{
    int taskN = 0;
    cin >> taskN;
    
    string* taskType = new string[4];
    taskType[0] = "declare";
    taskType[1] = "assignString";
    taskType[2] = "assignObject";
    taskType[3] = "print";
    taskType[4] = "subtractObject"
    
    string* tasks = new string[taskN];
    string* objects = new string[taskN];
    string* added = new string[taskN];
    for(int i = 0; i < taskN; i++){
        cin >> tasks[i] >> objects[i];
        if(tasks[i] != "print")
            cin >> added[i];
        else
            added[i] = "";
    }
    
    MyString* stringArr[100];
    int createdMyString = 0;
    for(int i = 0; i < taskN; i++)
    {
        if(tasks[i] == taskType[0])
        {
            declareString(stringArr, objects, added, i, createdMyString);
            createdMyString++;

        }else if(tasks[i] == taskType[1])
        {
            assignString(stringArr, objects, added, i, createdMyString);
            
        }else if(tasks[i] == taskType[2])
        {
            assignObject(stringArr, objects, added, i, createdMyString);
            
        }else if(tasks[i] == taskType[3])
        {
            print(stringArr, objects, i, createdMyString);
        }else if(task[i] == taskType[4])
        {
            subtractObject()
        }
    }
    
    return 0;
}

void declareString(MyString* stringArr[], string* objects, string* added, int i, int createdMyString)
{
    if(added[i].find("\"") != string ::npos)
    {
        string firstStr = "";
        string assignStr = "";
        if(added[i].length() != 2){
            firstStr = added[i].substr(added[i].find("\"")+1);
            assignStr = firstStr.substr(0, firstStr.find("\""));
        }
        stringArr[createdMyString] = new MyString(objects[i], assignStr);
    }
    else if(added[i].find("+") != string::npos)
    {
        string str = added[i];
        size_t addCnt = 0;
        while(str.find("+") != string::npos){
            str = str.substr(str.find("+") + 1);  
            addCnt++;
        }
        
        string* variables = new string[addCnt + 1];
        for(int add = 0; add < addCnt + 1; add++)
        {
            if(added[i].find("+") != string::npos)
            {
                variables[add] = added[i].substr(0, added[i].find("+"));
                added[i] = added[i].substr(added[i].find("+") + 1);
            }
        }
        
        for(int add = 0; add < addCnt+1; add++)
        {
            int appointedIndex = 0;
            string name;
            for(int s = 0; s < createdMyString+1; s++)
            {
                if(variables[add] == stringArr[s]->getName()){
                    appointedIndex = s;
                    name = stringArr[s]->name;
                    break;
                }
            }
            if(add == 0)
            {
                stringArr[createdMyString] = new MyString(objects[i]);  // set up name
                *stringArr[createdMyString] = *stringArr[appointedIndex];  // send char and len to stringArr[i]
            }
        }
    }
    else if(added[i].find("*") != string ::npos)
    {
        string str = added[i].substr(0, added[i].find("*"));
        string numberStr = added[i].substr(added[i].find("*")+1);
        int num = stoi(numberStr);
        for(int s = 0; s < createdMyString+1; s++){
            string name = stringArr[s]->getName();
            if(str == name){
                stringArr[createdMyString] = new MyString(objects[i]);
                *stringArr[createdMyString] = *stringArr[s];
                break;
            }
        }
        
        *stringArr[createdMyString] = *stringArr[i] * num;
    }
};
    
void assignString(MyString* stringArr[], string* objects, string* added, int i, int createdMyString)
{
    string firstStr = "";
    string assignStr = "";
    if(added[i].length() != 2){
        firstStr = added[i].substr(added[i].find("\"")+1);
        assignStr = firstStr.substr(0, firstStr.find("\""));
    }
    if(objects[i].find("[") != string:: npos){  
        string appointedStr = objects[i].substr(0, objects[i].find("["));
        string indexStr = objects[i].substr(objects[i].find("[")+1, objects[i].find("]")-objects[i].find("[")-1);
        int index = stoi(indexStr);
        for(int s = 0; s < createdMyString; s++){
            string name = stringArr[s]->getName();
            if(appointedStr == name)
            {  
                string awaitReplaceStr = stringArr[s]->getStr();
                string replacedStr = awaitReplaceStr.replace(index, 1, assignStr);
                
                *stringArr[s] = replacedStr;
                break;
            }
        }
    }else
    {
        int appointedIndex = findAppointedIndex(stringArr, objects, i, createdMyString);
        
        *stringArr[appointedIndex] = assignStr;
    }
}
void assignObject(MyString* stringArr[], string* objects, string* added, int i, int createdMyString)
{ 
    if(added[i].find("+") != string::npos)
    {
        string str = added[i];
        size_t addCnt = 0;
        while(str.find("+") != string::npos)
        {
            str = str.substr(str.find("+") + 1);  
            addCnt++;
        }
        string* variables = new string[addCnt + 1];  
        for(int add = 0; add < addCnt+1; add++)
        {
            if(added[i].find("+") != string::npos)
            {
                variables[add] = added[i].substr(0, added[i].find("+"));
                added[i] = added[i].substr(added[i].find("+") + 1);
            }
        }
        
        int appointedIndex = findAppointedIndex(stringArr, objects, i, createdMyString);
        
        for(int add = 0; add < addCnt+1; add++)
        {
            for(int s = 0; s < createdMyString; s++)
            {
                if(variables[add] == stringArr[s]->getName() && add == 0)
                {
                    *stringArr[appointedIndex] = *stringArr[s];
                    break;
                }
            }
        }
    }
    else if(added[i].find("*") != string ::npos)
    {
        int appointedIndex = findAppointedIndex(stringArr, objects, i, createdMyString);

        string str = added[i].substr(0, added[i].find("*"));
        string numberStr = added[i].substr(added[i].find("*")+1);
        int num = stoi(numberStr);
        for(int s = 0; s < createdMyString+1; s++)
        {
            string name = stringArr[s]->name;
            if(str == name)
            {
                *stringArr[appointedIndex] = *stringArr[s];
                break;
            }
        }
        
        *stringArr[appointedIndex] = *stringArr[appointedIndex] * num;
    }
    
}

int findAppointedIndex(MyString* stringArr[], string* someArr, int i, int createdMyString)
{ 
    int appointedIndex = 0;
    for(int s = 0; s < createdMyString + 1; s++)
    {
        if(someArr[i] == stringArr[s]->getName())
        {
            appointedIndex = s;
            break;
        }
    }
    
    return appointedIndex;
}
void print(MyString* stringArr[], string* objects, int i, int createdMyString)
{
    if(objects[i].find("[") != string::npos)
    {
        string appointedStr = objects[i].substr(0, objects[i].find("["));
        string indexStr = objects[i].substr(objects[i].find("[")+1, 1);
        int index = stoi(indexStr);
        int appointedIndex = 0;
        for(int s = 0; s < createdMyString+1; s++)
        {
            if(appointedStr == stringArr[s]->getName())
                appointedIndex = s;
                break;
            }
        }
        string s = stringArr[appointedIndex]->getStr();
        char* strTransChar = new char[s.length() + 1];
        strcpy(strTransChar, s.c_str());
        cout << strTransChar[index] << endl;
    }
}

