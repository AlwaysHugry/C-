#include  <iostream>
#include  <vector>
using  namespace  std;
class  Book
{
    public :
    Book(){
        m_ID = 0;
    }
    ~Book(){};
    Book(const Book& other){
        m_ID = other.m_ID;
        m_Name = other.m_Name;
        m_Introduction = other.m_Introduction;
        m_Author = other .m_Author;
        m_Date = other .m_Date;
        m_Page = other .m_Page;
    }
    void SetID(unsigned int s){
        m_ID = s;
    }
    unsigned int GetID()
    {
        return m_ID;
    }
    void SetName(string s)
    {
        m_Name = s;
    }
    string GetName()
    {
        return m_Name;
    }
    void SetIntroduction(string s)
    {
        m_Introduction = s;
    }
    string GetIntroduction()
    {
        return m_Introduction;
    }
    void SetAuthor(string s)
    {
        m_Author = s;
    }
    string GetAuthor()
    {
        return m_Author;
    }
    void SetDate(string s)
    {
        m_Date = s;
    }
    string GetDate()
    {
        return m_Date;
    }
    void SetPage(unsigned int s)
    {
        m_Page = s;
    }
    unsigned int GetPage()
    {
        return m_Page;
    }
    private :
    unsigned int m_ID;//���

    string m_Name;//����

    string m_Introduction;//���

    string m_Author;//����

    string m_Date;//����

    unsigned int m_Page;//ҳ��
};
//���ڴ˴�����Book��ĳ�Ա����ʵ��

class  Store
{
    public :
        Store()
        {
           cout<<"Store default constructor called!"<<endl;
        }
        Store(int n)
        {
            vector<Book>m_Bookss(n);
            cout<<"Store constructor with (int n) called!"<<endl;
        }
        ~Store()
        {
            cout<<"Store destructor called!"<<endl;
        }
        Store(const Store& other)
        {
            m_Books = other.m_Books;
            cout<<"Store copy constructor called!"<<endl;
        }
        void in(const Book& other)
        {
            m_Books.push_back(other);
        }
        Book findbyName(string name);
        Book findbyID(int ID);
        void out(string name);
        void printList();
        int GetCount()
        {
            return m_Books.size();
        }
    private :
        vector<Book> m_Books;
};
//���ڴ˴�����Store��ĳ�Ա����ʵ��
Book Store::findbyID(int ID)
{
    for(int i=0;i<m_Books.size();i++)
    {
        if(m_Books[i].GetID()==ID)
        return m_Books[i];
    }
    return Book();
}
Book Store::findbyName(string n)
{
    for(int i=0;i<m_Books.size();i++)
    {
        if(m_Books[i].GetName()==n)
        return m_Books[i];
    }
    return Book();
}
void Store::out(string name)
{
    vector<Book>::iterator it = m_Books.begin();
	for(;it!=m_Books.end();it++)
	{
		if((*it).GetName()==name)
		{
			it = m_Books.erase(it);
		}
	} 
}
void Store::printList()
{
    cout<<"There are totally "<<m_Books.size()<<" Books:"<<endl;
    for(int i=0;i<m_Books.size();i++)
    {
        if (m_Books[i].GetID() != 0)
            cout << "ID=" << m_Books[i].GetID() << ";  " << "Name:" << m_Books[i].GetName() << ";  " << "Author:" << m_Books[i].GetAuthor() << ";  " << "Date:" << m_Books[i].GetDate() << ";  " << endl;
        
    }
}
int  main()
{
        Store  s;
        Book  b1,b2,b3;
        b1.SetID(1);
        b1.SetName("C++  ���Գ������(��4��)");
        b1.SetAuthor("֣��");
        b1.SetIntroduction("����C++����������֪ʶ");
        b1.SetDate("201007");
        b1.SetPage(529);
        b2.SetID(2);
        b2.SetName("��ɢ��ѧ");
        b2.SetAuthor("��Т��");
        b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��");
        b2.SetDate("198209");
        b2.SetPage(305);
        b3.SetID(3);
        b3.SetName("c�������");
        b3.SetAuthor("̷��ǿ");
        b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��");
        b3.SetDate("201006");
        b3.SetPage(355);

        cout<<"��һ�������"<<endl;
        s.in(b1);
        cout<<"�ڶ��������"<<endl;
        s.in(b2);
        cout<<"�����������"<<endl;
        s.in(b3);
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;
        cout  <<"���Ҳ�����ͼ�飺��ɢ��ѧ"  <<  endl;
        Book  tmpbook=s.findbyName("��ɢ��ѧ");
        if(tmpbook.GetID()!=0)
        {
                s.out("��ɢ��ѧ");
                cout  <<"��ɢ��ѧ  �ѳɹ�����"  <<  endl;
        }
        else
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;

        cout  <<"����ͼ��  ID��3"  <<  endl;
        tmpbook=s.findbyID(3);
        if(tmpbook.GetID()!=0)
                cout<<"�ҵ�IDΪ"<<3<<"���飬������"<<tmpbook.GetName()<<endl;
        else
                cout<<"û���ҵ�IDΪ"<<3<<"����"<<endl;

        cout  <<"����ͼ��  name����ɢ��ѧ"  <<  endl;
        tmpbook=s.findbyName("��ɢ��ѧ");
        if(tmpbook.GetID()!=0)
                cout<<"�ҵ�nameΪ��ɢ��ѧ���飬ID��"<<tmpbook.GetID()<<endl;
        else
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;

        cout<<"������п��ͼ�����Ϣ"<<endl;
        s.printList();
        cout<<"�������н���"<<endl;
        return  0;
}