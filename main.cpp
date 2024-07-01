
//PROJECT REGARDING
#include<iostream.h>	
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>

//################### STRUCTURE FOR DATE #################
struct dates //DECLARATION OF THE STRUCTURE
{
	int dd;
	int mm;
	int yy;
};

//########################### CLASS STOCK ######################

class stock        //DECLARATION OF THE CLASS STOCK
{
	int b_id;
	char b_name[30];
	char b_lang[30];
	char a_name[30];
	char p_name[30];
	int b_qty;
	float b_price;
	int b_yoe;
	dates dop ;
	char b_type[30];
	public:
	void input()      //INPUT FUNCTION INSIDE THE CLASS(STOCK)
	{
		gotoxy(1,2);
		cout<<"ENTER THE ID OF THE BOOK -:";
		gotoxy(45,2);
		cin>>b_id;
		gotoxy(1,4);
		cout<<"ENTER THE NAME OF THE BOOK -:";
		gotoxy(45,4);
		gets(b_name);
		gotoxy(1,6);
		cout<<"ENTER THE LANGUAGE OF THE BOOK -:";
		gotoxy(45,6);
		gets(b_lang);
		gotoxy(1,8);
		cout<<"ENTER THE PUBLISHAR NAME OF THE BOOK -:";
		gotoxy(45,8);
		gets(p_name);
		gotoxy(1,10);
		cout<<"ENTER THE AUTHOR'S NAME OF THE BOOK -:";
		gotoxy(45,10);
		gets(a_name);
		gotoxy(1,12);
		cout<<"ENTER THE QUANTITY OF THE BOOK -:";
		gotoxy(45,12);
		cin>>b_qty;
		gotoxy(1,14);
		cout<<"ENTER THE PRICE OF THE BOOK -:";
		gotoxy(45,14);
		cin>>b_price;
		gotoxy(1,16);
		cout<<"ENTER THE YEAR OF EDITION OF THE BOOK -:";
		gotoxy(45,16);
		cin>>b_yoe;
		gotoxy(1,18);
		cout<<"ENTER THE TYPE [SUBJECT] OF THE BOOK -:";
		gotoxy(45,18);
		gets(b_type);
		gotoxy(1,20);
		cout<<"ENTER THE DATE OF PURCHASE OF THE BOOK -:";
		gotoxy(47,20);
		cout<<"/";
		gotoxy(50,20);
		cout<<"/";
		gotoxy(45,20);
		cin>>dop.dd;
		gotoxy(47,20);
		cout<<"/";
		while(dop.dd<1 || dop.dd>31)     //condition check
		{
			gotoxy(45,20);
			cin>>dop.dd;
			gotoxy(47,20);
			cout<<"/";
		}
		gotoxy(48,20);
		cin>>dop.mm;
		gotoxy(50,20);
		cout<<"/";
		while(dop.mm<1 ||dop.mm>12)   //condition check
		{
			gotoxy(48,20);
			cin>>dop.mm;
			gotoxy(50,20);
			cout<<"/";
		}
		gotoxy(51,20);
		cin>>dop.yy;
		while(dop.yy<1950 ||dop.yy>2020)   //condition check
		{
			gotoxy(51,20);
			cin>>dop.yy;
		}
	}

void output()  //OUTPUT FUNCTION INSIDE THE CLASS(STOCK)
{
		gotoxy(1,2);
		cout<<" THE ID OF THE BOOK -:";
		gotoxy(45,2);
		cout<<b_id;
		gotoxy(1,4);
		cout<<" THE NAME OF THE BOOK -:";
		gotoxy(45,4);
		puts(b_name);
		gotoxy(1,6);
		cout<<" THE LANGUAGE OF THE BOOK -:";
		gotoxy(45,6);
		puts(b_lang);
		gotoxy(1,8);
		cout<<" THE PUBLISHAR NAME OF THE BOOK -:";
		gotoxy(45,8);
		puts(p_name);
		gotoxy(1,10);
		cout<<" THE AUTHOR'S NAME OF THE BOOK -:";
		gotoxy(45,10);
		puts(a_name);
		gotoxy(1,12);
		cout<<" THE QUANTITY OF THE BOOK -:";
		gotoxy(45,12);
		cout<<b_qty;
		gotoxy(1,14);
		cout<<" THE PRICE OF THE BOOK -:";
		gotoxy(45,14);
		cout<<b_price;
		gotoxy(1,16);
		cout<<" THE YEAR OF EDITION OF THE BOOK -:";
		gotoxy(45,16);
		cout<<b_yoe;
		gotoxy(1,18);
		cout<<" THE TYPE [SUBJECT] OF THE BOOK -:";
		gotoxy(45,18);
		puts(b_type);
		gotoxy(1,20);
		cout<<" THE DATE OF PURCHASE OF THE BOOK IS -:";
		gotoxy(45,20);
		cout<<dop.dd<<"-"<<dop.mm<<"-"<<dop.yy;
	}
	void report(int r)   //report function inside the class
	{
		gotoxy(7,r);
		cout<<b_id;
		gotoxy(25,r);
		cout<<b_name;
		gotoxy(50,r);
		cout<<b_qty;
		gotoxy(75,r);
		cout<<b_price;
	}
	int nm()          //RETURN FUNCTIONS OF CLASS(STOCK)
	{
		return(b_id);
	}
	char *name1()
	{
		return(b_name);
	}
	char *aname2()
	{
		return(a_name);
	}
	char *pname3()
	{
		return(p_name);
	}
	int dat4()
	{
		return dop.dd;
	}
	int month5()
	{
		return dop.mm;
	}
	int year6()
	{
		return dop.yy;
	}
	void nnic()        //FUNCTION OF INCREAMENT(STOCK)
	{
		b_qty=b_qty+1;
	}
	void nndc()       //FUNCTION OF DECREAMENT(STOCK)
	{
		b_qty=b_qty-1;
	}
};
void addrec()           //FUNCTION OF ADD RECORD
{
	cleardevice();
	stock s;
	ofstream fout;
	fout.open ("stock.dat",ios::app | ios::binary);
	char ht='y';
	while (ht=='y'|| ht=='Y')
	{
		cleardevice();
		s.input();
		fout.write((char*)&s,sizeof (s));
		cout<<"\n DO YOU WANT TO CONTINUE [Y/N] -:\t";
		cin>>ht;
	}
	fout.close();
}
void disprec()           //FUNCTION OF DISPLAY RECORD
{
	cleardevice();
	stock z;
	ifstream fin;
	fin.open("stock.dat",ios::in);
	while(fin)
	{
		fin.read((char*)&z,sizeof (z));

		if(fin)
		{
			cleardevice();
			z.output();

			getch();
		}
	}
	fin.close();
}
void srec()              //FUNCTION FOR SEARCHING RECORD
{
	cleardevice();
	stock sz;
	char name[30];
	char th[30];
	int ec,ch;
	int flag;
	gotoxy(1,2);
	cout<<"ENTER THE CHOICE ON WHICH BASIS YOU WANT TO SEARCH";
	gotoxy(1,4);
	cout<<"1.BOOK ID";
	gotoxy(1,6);
	cout<<"2.BOOK NAME";
	gotoxy(1,8);
	cout<<"3.AUTHOR'S NAME";
	gotoxy(1,10);
	cout<<"4.PUBLISHER'S NAME";
	gotoxy(1,12);
	cout<<"ENTER YOUR CHOICE [1-4]";
	gotoxy(45,14);
	cin>>ch;
	ifstream sfin;
	sfin.open("stock.dat",ios::in);
	if(ch==1)
	{
		gotoxy(1,18);
		cout<<"ENTER THE BOOK ID -:";
		cin>>ec;
	}
	if(ch==2)
	{
		gotoxy(1,18);
		cout<<"ENTER THE BOOK NAME -:";
		gets(name);
	}
	if(ch==3)
	{
		gotoxy(1,18);
		cout<<"ENTER THE AUTHOR'S NAME -:";
		gets(name);
	}
	if(ch==4)
	{
		gotoxy(1,18);
		cout<<"ENTER THE PUBLISHER'S NAME -:";
		gets(name);
	}
	while(sfin)
	{
		sfin.read((char*)&sz,sizeof (sz));
		if(sfin)
		{
		if(sz.nm()==ec||strcmp(sz.name1(),name)==0||strcmp(sz.ana
me2(),name)==0||strcmp(sz.aname2(),name)==0||strcmp(sz.an
ame2(),name)==0)
		{
			cleardevice();
			sz.output();
			flag=1;
			break;
		}
		}
	}
	if(flag==0)
	{
		cleardevice();
		gotoxy(1,2);
		cout<<"\n RECORD NOT FOUND\n";
	}
	sfin.close();
}

void modify()            //FUNCTION FOR MODIFICATION OF RECORD
{
	cleardevice();
	fstream f;
	char nm[3];
	f.open("stock.dat",ios::in|ios::out|ios::binary);
	stock sm;
	char name[30];
	int ec,choice;
	gotoxy(1,2);
	cout<<"ENTER THE CHOICE ON WHICH BASIS YOU WANT TO SEARCH";
	gotoxy(1,4);
	cout<<"1.BOOK ID ";
	gotoxy(1,6);
	cout<<"2.BOOK NAME";
	gotoxy(1,8);
	cout<<"3.AUTHOR'S NAME";
	gotoxy(1,10);
	cout<<"4.PUBLISHER'S NAME";
	gotoxy(1,12);
	cout<<"ENTER YOUR CHOICE [1-4]";
	gotoxy(30,12);
	cin>>choice;
	if(choice==1)
	{
		gotoxy(30,14);
		cout<<"ENTER THE BOOK ID -:";
		cin>>ec;
	}
	if(choice==2)
	{
		gotoxy(30,14);
		cout<<"ENTER THE BOOK NAME -:";
		gets(name);
	}
	if(choice==3)
	{
		gotoxy(30,14);
		cout<<"ENTER THE AUTHOR'S NAME -:";
		gets(name);
	}
	if(choice==4)
	{
		gotoxy(30,14);
		cout<<"ENTER THE PUBLISHER'S NAME -:";
		gets(name);
	}
	while(!f.eof())
	{
		f.read((char*)&sm,sizeof(sm));
		if(f)
		{
			if(sm.nm()==ec)
			{
				cleardevice();
				f.seekg(f.tellg() - sizeof(sm));
				sm.output();
				getch();
				cleardevice();
				sm.input();
				f.write((char *)&sm,sizeof(sm));
			}
			if(strcmp(sm.name1(),name)==0)
			{
				cleardevice();
				f.seekg(f.tellg()-sizeof (sm));
				sm.output();
				getch();
				cleardevice();
				sm.input();
				f.write((char *)&sm,sizeof (sm));
			}
			if(strcmp(sm.aname2(),name)==0)
			{
				cleardevice();
				f.seekg(f.tellg()-sizeof (sm));
				sm.output();
				getch();
				cleardevice();
				sm.input();
				f.write((char *)&sm,sizeof (sm));
			}
			if(strcmp(sm.pname3(),name)==0)
			{
				cleardevice();
				f.seekg(f.tellg()-sizeof (sm));
				sm.output();
				getch();
				cleardevice();
				sm.input();
				f.write((char *)&sm,sizeof (sm));
			}
		}
	}
	f.close();
}
void delrec()            //FUNCTION FOR DELETION OF RECORD
{
	cleardevice();
	stock ds;
	char name[30];
	int ec,chl;
	char c;
	ifstream fdel;
	fdel.open("stock.dat",ios::in|ios::binary);
	ofstream fte;
	fte.open("temp.dat",ios::out|ios::binary);
	gotoxy(1,2);
	cout<<"ENTER THE CHOICE ON WHICH BASIS YOU WANT TO SEARCH";
	gotoxy(1,4);
	cout<<"1.BOOK ID";
	gotoxy(1,6);
	cout<<"2.BOOK NAME";
	gotoxy(1,8);
	cout<<"3.AUTHOR'S NAME";
	gotoxy(1,10);
	cout<<"4.PUBLISHER'S NAME";
	gotoxy(1,12);
	cout<<"5.EXIT";
	gotoxy(1,14);
	cout<<"ENTER YOUR CHOICE [1-4]";
	gotoxy(30,15);
	cin>>chl;
	if(chl==1)
	{
		gotoxy(30,16);
		cout<<"ENTER THE BOOK ID -:";
		cin>>ec;
	}
	if(chl==2)
	{
		gotoxy(30,16);
		cout<<"ENTER THE BOOK NAME -:";
		gets(name);
	}
	if(chl==3)
	{
		gotoxy(30,16);
		cout<<"ENTER THE AUTHOR'S NAME -:";
		gets(name);
	}
	if(chl==4)
	{
		gotoxy(30,16);
		cout<<"ENTER THE PUBLISHER'S NAME -:";
		gets(name);
	}
	while(fdel)
	{
		fdel.read((char*)&ds,sizeof (ds));
		if(fdel)
		{
			if(ds.nm()==ec||strcmp(ds.name1(),name)==0||strcmp(ds.aname2(),name)==0||strcmp(ds.pname3(),name)==0)
			{
				cleardevice();
				ds.output();
				cout<<"\n DO YOU WANT TO DELETE THIS RECORD [Y/N] -:\t ";
				cin>>c;
				if(c=='n'||c=='N')
				{
					fte.write((char*)&ds,sizeof(ds));
				}
				break;
			}
			else
			{
				fte.write((char*)&ds,sizeof(ds));
			}
		}
	}
	fdel.close();
	fte.close();
	remove("stock.dat");
	rename("temp.dat","stock.dat");
	remove("temp.dat");
}

void streport1()            //REPORT OF STOCK
{
	cleardevice();
	stock st100;
	int flag=0,r=10;
	dates dp10;
	gotoxy(3,3);
	cout<<"ENTER THE DATE OF PURCHASE FOR SEARCHING -:";
	gotoxy(47,3);
	cout<<"/";
	gotoxy(50,3);
	cout<<"/";
	gotoxy(45,3);
	cin>>dp10.dd;
	gotoxy(47,3);
	cout<<"/";
	while(dp10.dd<1 || dp10.dd>31)     //condition check
	{
		gotoxy(45,3);
		cin>>dp10.dd;
		gotoxy(47,3);
		cout<<"/";
	}
	gotoxy(48,3);
	cin>>dp10.mm;
	gotoxy(50,3);
	cout<<"/";
	while(dp10.mm<1 ||dp10.mm>12)   //condition check
	{
		gotoxy(48,3);
		cin>>dp10.mm;
		gotoxy(50,3);
		cout<<"/";
	}
	gotoxy(51,3);
	cin>>dp10.yy;
	while(!(dp10.yy>=1950 && dp10.yy<=2020))     //condition check
	{
		gotoxy(51,3);
		cin>>dp10.yy;
	}

	cleardevice();
	ifstream finr1("stock.dat",ios::in | ios::binary);

	while(finr1)
	{
		gotoxy(30,3);
		cout<<"OXFORD LIBRARY";
		gotoxy(30,4);
		cout<<"===============";
		gotoxy(35,6);
		cout<<"BOOK MANIFEST";
		gotoxy(35,7);
		cout<<"=============";
		gotoxy(5,8);
		cout<<"BOOK ID";
		gotoxy(24,8);
		cout<<"BOOK NAME";
		gotoxy(45,8);
		cout<<"BOOK QUANTITY";
		gotoxy(70,8);
		cout<<"BOOK PRICE";
		gotoxy(1,9);
	cout<<"===============================================================================";
		finr1.read((char *)&st100,sizeof(st100));
		if(finr1)
		{

			if(dp10.dd==st100.dat4() && dp10.mm==st100.month5() && dp10.yy==st100.year6())
			{
				st100.report(r);
				r=r+2;
				flag=1;
			}
			if(r>25)
			{
				r=10;
				getch();
				cout<<"\nPLEASE PRESS ANY KEY TO CONTINUE :\t";
				cleardevice();
			}
		}
	}
	finr1.close();
	if(flag==0)
	{
		cleardevice();
		cout<<"\n RECORD NOT FOUND\n";
	}
}

//##########################   CLASS MEMBER ##################
  
class member               //DECLARATION OF MEMBER CLASS
{
	char m_name[30];
	int m_id;
	char m_add[40];
	char m_type[30];
	int maxqty;
	int isqty;
	public:
	void getdata()           //FUNCTION FOR INPUT DATA IN MEMBER CLASS
	{
		gotoxy(1,2);
		cout<<" ENTER THE ID OF THE MEMBER -:";
		gotoxy(45,2);
		cin>>m_id;
		gotoxy(1,4);
		cout<<" ENTER THE NAME OF THE MEMBER -:";
		gotoxy(45,4);
		gets(m_name);
		gotoxy(1,6);
		cout<<" ENTER THE ADDRESS OF THE MEMBER -:";
		gotoxy(45,6);
		gets(m_add);
		gotoxy(1,8);
		cout<<" ENTER THE TYPE [DIAMOND/GOLD/SILVER]OF THE 
MEMBERSHIP -:";
		gotoxy(70,8);
		cin>>m_type;
		if((strcmp(m_type,"DIAMOND")==0)||(strcmp(m_type,"diamond")==0))
		{
			maxqty=3;
		}
		if((strcmp(m_type,"gold")==0)||(strcmp(m_type,"GOLD")==0))
		{
			maxqty=2;
		}
		if((strcmp(m_type,"SILVER")==0)||(strcmp(m_type,"silver")==0))
		{
			maxqty=1;
		}
		isqty=0;
	}
	void putdata()         //FUNCTION FOR OUTPUT(MEMBER)
	{
		gotoxy(1,2);
		cout<<" THE ID OF THE MEMBER -:";
		gotoxy(45,2);
		cout<<m_id;
		gotoxy(1,4);
		cout<<" THE NAME OF THE MEMBER -:";
		gotoxy(45,4);
		puts(m_name);
		gotoxy(1,6);
		cout<<" THE ADDRESS OF THE MEMBER -:";
		gotoxy(45,6);
		puts(m_add);
		gotoxy(1,8);
		cout<<" THE TYPE [DIAMOND,GOLD,SILVER]  OF THE MEMBERSHIP -:";
		gotoxy(60,8);
		cout<<m_type;
		gotoxy(1,10);
		cout<<" MAXMIUM QTY. OF BOOKS THIS MEMBER CAN ISSUE -:";
		gotoxy(60,10);
		cout<<maxqty;
		gotoxy(1,12);
		cout<<" NUMBER OF BOOKS ISSUED -:";
		gotoxy(45,12);
		cout<<isqty;
	}
	void memreport(int r)             //REPORT OF MEMBER CLASS
	{
		gotoxy(6,r);
		cout<<m_id;
		gotoxy(24,r);
		cout<<m_name;
		gotoxy(44,r);
		cout<<m_add;
		gotoxy(70,r);
		cout<<m_type;
	}
	int mmid()                    //RETURN FUNCTION(MEMBER)
	{
		return m_id;
	}
	char *mname1()
	{
		return(m_name);
	}
	int mmax()
	{
		return maxqty;
	}
	int mis()
	{
		return isqty;
	}
	char *mtype4()
	{
		return(m_type);
	}
	void mmic()                    //FUCTION FOR INCREMENT DATA(MEMBER)
	{
		isqty=isqty+1;
	}
	void mmdc()                 //FUNCTION FOR DECREMENT DATA(MEMBER)
	{
		isqty=isqty-1;
	}
};




void addition_rec()      //FUNCTION FOR ADD DATA IN MEMBER CLASS
{
	cleardevice();
	member m;
	ofstream f_mem;
	f_mem.open ("member.dat",ios::app | ios::binary);
	char a='y';
	while (a=='y'||a=='Y')
	{
		cleardevice();
		m.getdata();
		f_mem.write((char*)&m,sizeof (m));
		cout<<"\n DO YOU WANT TO CONTINUE [Y/N] -:\t";
		cin>>a;
	}
	f_mem.close();
}
void display_rec()             //FUNCTION OF DISPLAY RECORD(MEMBER)
{
	cleardevice();
	member p;
	ifstream fdis;
	fdis.open("member.dat",ios::in);
	while(fdis)
	{
		fdis.read((char*)&p,sizeof (p));
		if(fdis)
		{
			cleardevice();
			p.putdata();
			getch();
		}
	}
	fdis.close();
}
void search_rec()               //FUNCTION FOR SEARCHING DATA(MEMBER)
{
	cleardevice();
	member bm;
	char kj[30];
	int ec,cc;
	int cnt=0;
	gotoxy(1,2);
	cout<<"ENTER THE CHOICE ON WHICH BASIS YOU WANT TO SEARCH";
	gotoxy(1,4);
	cout<<"1.MEMBER ID";
	gotoxy(1,6);
	cout<<"2.MEMBER NAME";
	gotoxy(1,8);
	cout<<"ENTER YOUR CHOICE[1-2]";
	gotoxy(45,8);
	cin>>cc;


	if(cc==1)
	{
		gotoxy(1,10);
		cout<<"ENTER THE MEMBER ID -:";
		gotoxy(45,10);
		cin>>ec;
	}
	if(cc==2)
	{
		gotoxy(1,10);
		cout<<"ENTER THE MEMBER NAME -:";
		gotoxy(45,10);
		gets(kj);
	}
	ifstream fser;
	fser.open("member.dat",ios::in  | ios::binary);
	while(fser)
	{
		fser.read((char *)&bm,sizeof(bm));
		if(fser)
		{
			if(bm.mmid()==ec || strcmp(bm.mname1(),kj)==0)
			{
				cleardevice();
				bm.putdata();
				cnt=1;
				break;
			}
		}
	}

	if(cnt==0)
	{
		cout<<"\n MEMBER NOT FOUND\n";
	}
	fser.close();
}

void modification()              //FUNCTION FOR MODIFICATION DATA(MEMBER)
{
	cleardevice();
	fstream fmod;
	fmod.open("member.dat",ios::in|ios::out|ios::binary);
	member d;
	char name[30];
	int ec,cm;
	gotoxy(1,2);
	cout<<"ENTER THE CHOICE ON WHICH BASIS YOU WANT TO SEARCH";
	gotoxy(1,4);
	cout<<"1.MEMBER ID";
	gotoxy(1,6);
	cout<<"2.MEMBER NAME";
	gotoxy(1,8);
	cout<<"ENTER YOUR CHOICE[1-2]";
	gotoxy(45,8);
	cin>>cm;
	if(cm==1)
	{
		gotoxy(1,10);
		cout<<"ENTER THE MEMBER ID -:";
		gotoxy(45,10);
		cin>>ec;
	}
	else if(cm==2)
	{
		gotoxy(1,10);
		cout<<"ENTER THE MEMBER NAME -:";
		gotoxy(45,10);
		gets(name);
	}
	while(!fmod.eof())
	{
		fmod.read((char*)&d,sizeof (d));
		if(fmod)
		{
			if(d.mmid()==ec || strcmp(d.mname1(),name)==0)
			{
				cleardevice();
				fmod.seekg(fmod.tellg() - sizeof(d));
				d.putdata();
				getch();
				cleardevice();
				d.getdata();
				fmod.write((char *)&d,sizeof(d));
				break;
			}
		}
	}
	fmod.close();
}
void memdel()               //FUNCTION FOR DELETION(MEMBER)
{
	cleardevice();
	member j;
	char name[30];
	int ec,ch;
	char c;
	ifstream fmdel;
	fmdel.open("member.dat",ios::in|ios::binary);
	ofstream fmd;
	fmd.open("temp.dat",ios::out|ios::binary);
	gotoxy(1,2);
	cout<<"ENTER THE CHOICE ON WHICH BASIS YOU WANT TO SEARCH";
	gotoxy(1,4);
	cout<<"1.MEMBER ID";
	gotoxy(1,6);
	cout<<"2.MEMBER NAME";
	gotoxy(1,8);
	cout<<"ENTER YOUR CHOICE[1-2]";
	gotoxy(45,8);
	cin>>ch;
	if(ch==1)
	{
		gotoxy(1,10);
		cout<<"ENTER THE MEMBER ID -:";
		gotoxy(45,10);
		cin>>ec;
	}
	if(ch==2)
	{
		gotoxy(1,10);
		cout<<"ENTER THE MEMBER NAME -:";
		gotoxy(45,10);
		gets(name);
	}
	while(fmdel)
	{
		fmdel.read((char*)&j,sizeof(j));
		if(fmdel)
		{
			if(j.mmid()==ec || strcmp(j.mname1(),name)==0)
			{
				cleardevice();
				j.putdata();
				cout<<"\n DO YOU WANT TO DELETE THIS RECORD [Y/N] -:\t ";
				cin>>c;
				if(c=='n'||c=='N')
				{
					fmd.write((char*)&j,sizeof(j));
				}
			}
			else
			{
				fmd.write((char*)&j,sizeof(j));
			}
		 }
	}
	fmdel.close();
	fmd.close();
	remove("member.dat");
	rename("temp.dat","member.dat");
	remove("temp.dat");
}
void memreport1()   //REPORT OF CLASS MEMBER
{
	cleardevice();
	member h;
	int ec;
	int cm=0;
	int r;
	ifstream frep;
	frep.open("member.dat",ios::in|ios::binary);
	gotoxy(1,2);
	cout<<"PLEASE ENTER THE MEMBER CODE FOR REPORT -:";
	gotoxy(50,2);
	cin>>ec;
	r=10;
	cleardevice();
	while(frep)
	{
		gotoxy(30,3);
		cout<<"_______________ LIBRARY";
		gotoxy(30,4);
		cout<<"=======================";
		gotoxy(35,6);
		cout<<"MEMBER MANIFEST";
		gotoxy(35,7);
		cout<<"===============";
		gotoxy(4,8);
		cout<<"MEMBER ID";
		gotoxy(22,8);
		cout<<"MEMBER NAME";
		gotoxy(43,8);
		cout<<"MEMBER'S ADDRESS";
		gotoxy(68,8);
		cout<<"MEMBER TYPE";
		gotoxy(1,9);
		cout<<"*******************************************************
*************************";
		frep.read((char *)&h,sizeof(h));
		if(frep)
		{
			if(h.mmid()==ec)
			{
				h.memreport(r);
				r=r+2;
				cm=1;
			}
		}
		if(r>24)
		{
			r=10;
			getch();
			cout<<"\n PLEASE PRESS ANY KEY TO CONTINUE -:\t";
			clrscr();
		}
	}
	if(cm==0)
	{
		cout<<"\n RECORD NOT FOUND\n";
	}
	frep.close();
}




/###################### CLASS TRANSACTION ###################/
class trans      //DECLARATION OF TRANSACTION CLASS
{
	int mid;
	char mname[30];
	char mtype[30];
	int bid;
	char bname[30];
	char t_type[30];
	dates t_date;
	public:
	void copymember(int id,char name[],char type[])
//COPY FUNCTION(MEMBER)
	{
		mid=id;
		strcpy(mname,name);
		strcpy(mtype,type);
	}
	void copybook(int bd,char bn[],char type[])   
//COPY FUNCTION(STOCK)
	{
		bid=bd;
		strcpy(bname,bn);
		strcpy(t_type,type);
	}
	void tranreport(int r)      		//REPORT FUNCTION OF TRANS.
	{
		gotoxy(6,r);
		cout<<mid;
		gotoxy(25,r);
		puts(mname);
		gotoxy(45,r);
		cout<<bid;
		gotoxy(60,r);
		puts(bname);
	}
};
void issue()            //RETURN FUNCTION OF CLASS
{
	cleardevice();
	member g;
	stock k;
	trans t;
	dates dl4;
	int md,flag=0,bd;
	fstream fmem("member.dat",ios::binary|ios::in|ios::out);
	fstream fst("stock.dat",ios::binary|ios::in|ios::out);
	ofstream fout("trans.dat",ios::binary|ios::app);
	gotoxy(1,2);
	cout<<"ENTER THE MEMBER-ID TO ISSUE -:";
	gotoxy(45,2);
	cin>>md;
	while(fmem)
	{
		fmem.read((char*)&g,sizeof(g));
		if(fmem)
		{
			if(md==g.mmid() && g.mmax()>g.mis())
			{
				t.copymember(g.mmid(),g.mname1(),g.mtype4());
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
	{
		gotoxy(1,4);
		cout<<"ENTER THE BOOK-ID -:";
		gotoxy(45,4);
		cin>>bd;
		gotoxy(1,6);
		cout<<"ENTER THE DATE OF ISSUE OF THE BOOK -:";
		gotoxy(47,6);
		cout<<"/";
		gotoxy(50,6);
		cout<<"/";
		gotoxy(45,6);
		cin>>dl4.dd;
		gotoxy(47,6);
		cout<<"/";
		while(dl4.dd<1 || dl4.dd>31)     //condition check
		{
			gotoxy(45,6);
			cin>>dl4.dd;
			gotoxy(47,6);
			cout<<"/";
		}
		gotoxy(48,6);
		cin>>dl4.mm;
		gotoxy(50,6);
		cout<<"/";
		while(dl4.mm<1 ||dl4.mm>12)   //condition check
		{
			gotoxy(48,6);
			cin>>dl4.mm;
			gotoxy(50,6);
			cout<<"/";
		}
		gotoxy(51,6);
		cin>>dl4.yy;
		while(dl4.yy<1950 ||dl4.yy>2011)     //condition check
		{
			gotoxy(51,6);
			cin>>dl4.yy;
		}
		while(fst)
		{
			fst.read((char *)&k,sizeof(k));
			if(fst)
			{
				getch();
				if(bd==k.nm())
				{
					t.copybook(k.nm(),k.name1(),"ISSUE");
					fout.write((char*)&t,sizeof(t));
					k.nndc();
					g.mmic();
					fmem.seekg(fmem.tellg()-sizeof(g));
					fmem.write((char*)&g,sizeof(g));
					fst.seekg(fst.tellg()-sizeof(k));
					fst.write((char*)&k,sizeof(k));
				 }
			}
		}
	}
fout.close();
fmem.close();
fst.close();
}
void return_book()   //RETURN FUNCTION OF CLASS
{
	cleardevice();
	member e;
	stock y;
	trans t;
	dates dh5;
	int md,flag=0,bd;
	fstream tdm("member.dat",ios::binary|ios::in|ios::out);
	fstream fstt("stock.dat",ios::binary|ios::in|ios::out);
	fstream foutt("trans.dat",ios::binary|ios::out);
	gotoxy(1,2);
	cout<<"ENTER THE MEMBER-ID FOR SEARCHING -:";
	gotoxy(45,2);
	cin>>md;
	while(tdm)
	{
		tdm.read((char*)&e,sizeof(e));
		if(tdm)
		{
			if(md==e.mmid())
			{
				t.copymember(e.mmid(),e.mname1(),e.mtype4());
				flag=1;
				break;
			}
		}
	}



	if(flag==1)
	{
		gotoxy(1,4);
		cout<<"ENTER THE BOOK-ID -:";
		gotoxy(45,4);
		cin>>bd;
		gotoxy(1,6);
		cout<<"ENTER THE DATE OF RETURN OF THE BOOK -:";
		gotoxy(47,6);
		cout<<"/";
		gotoxy(50,6);
		cout<<"/";
		gotoxy(45,6);
		cin>>dh5.dd;
		gotoxy(47,6);
		cout<<"/";
		while(dh5.dd<1 || dh5.dd>31)     //condition check
		{
			gotoxy(45,6);
			cin>>dh5.dd;
			gotoxy(47,6);
			cout<<"/";
		}
		gotoxy(48,6);
		cin>>dh5.mm;
		gotoxy(50,6);
		cout<<"/";
		while(dh5.mm<1 ||dh5.mm>12)   //condition check
		{
			gotoxy(48,6);
			cin>>dh5.mm;
			gotoxy(50,6);
			cout<<"/";
		}
		gotoxy(51,6);
		cin>>dh5.yy;
		while(dh5.yy<1950 ||dh5.yy>2011)     //condition check
		{
			gotoxy(51,6);
			cin>>dh5.yy;
		}
		while(fstt)
		{
			fstt.read((char*)&y,sizeof(y));
			if(fstt)
			{				if(bd==y.nm())
				{
					t.copybook(y.nm(),y.name1(),"ISSUE");
					foutt.write((char*)&t,sizeof(t));
					y.nnic();
					e.mmdc();
					tdm.seekg(tdm.tellg()-sizeof(e));
					tdm.write((char*)&e,sizeof(e));
					fstt.seekg(fstt.tellg()-sizeof(y));
					fstt.write((char*)&y,sizeof(y));
				}
			}
		}
	}
foutt.close();
tdm.close();
fstt.close();
}
void tr_report()      //REPORT OF TRANS OF FILE
{
	cleardevice();
	trans  u;
	cleardevice();
	int flag=0;
	int r;
	ifstream frepor;
	frepor.open("trans.dat",ios::in|ios::binary);
	r=10;
	cleardevice();
	while(frepor)
	{
		gotoxy(35,3);
		cout<<"OXFORD LIBRARY";
		gotoxy(35,4);
		cout<<"===============";
		gotoxy(30,6);
		cout<<"TRANSACTION MANIFEST";
		gotoxy(30,7);
		cout<<"====================";
		gotoxy(4,8);
		cout<<"MEMBER ID";
		gotoxy(22,8);
		cout<<"MEMBER NAME";
		gotoxy(43,8);
		cout<<"BOOK ID";
		gotoxy(60,8);
		cout<<"BOOK NAME";
		gotoxy(1,9);
		cout<<"*******************************************************
*************************";
		frepor.read((char *)&u,sizeof(u));
		if(frepor)
		{

			u.tranreport(r);
			r=r+2;
			flag=1;
		}
		if(r>24)
		{	r=10;
			getch();
			cout<<"\n PLEASE PRESS ANY KEY TO CONTINUE -:\n";
			clrscr();
		}
	}
	if(flag==0)
	{
		 cout<<"\n RECORD NOT FOUND\n";
	}
	frepor.close();
}
//############################   VOID MAIN ######################//
void menu()           //FUNCTION OF MENU
{
	cleardevice();
	setbkcolor(MAGENTA);
	setcolor(WHITE);
	rectangle(0,0,639,479);
	settextstyle(4,0,4);
	outtextxy(175,25,"****MAIN MENU****");
	settextstyle(1,0,2);
	outtextxy(175,75,"^^^^^^^^^^^^^^^^^^^^^^^^^^");
	outtextxy(150,100,"1.STOCK FILE");
	outtextxy(150,125,"2.MEMBER FILE");
	outtextxy(150,150,"3.TRANSACTION FILE");
	outtextxy(150,175,"4.EXIT");
}
void menu2()
{
	cleardevice();
	setbkcolor(1);
	setcolor(3);
	rectangle(0,0,639,479);
	settextstyle(4,0,4);
	outtextxy(175,25,"****STOCK'S-MENU ****");
	settextstyle(1,0,2);
	outtextxy(175,75,"^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	outtextxy(150,100,"1.ADD RECORD");
	outtextxy(150,125,"2.DISPLAY RECORD");
	outtextxy(150,150,"3.SEARCH RECORD");
	outtextxy(150,175,"4.MODIFY RECORD");
	outtextxy(150,200,"5.DELETE RECORD");
	outtextxy(150,225,"6.REPORT ");
	outtextxy(150,250,"7.EXIT FROM MENU");
	outtextxy(150,275,"8.EXIT FROM PROGRAM");
}
void menu3()
{
	cleardevice();
	setbkcolor(1);
	setcolor(3);
	rectangle(0,0,639,479);
	settextstyle(4,0,4);
	outtextxy(175,25,"****MEMBER'S-MENU ****");
	settextstyle(1,0,2);
	outtextxy(175,75,"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	outtextxy(150,100,"1.ADD RECORD");
	outtextxy(150,125,"2.DISPLAY RECORD");
	outtextxy(150,150,"3.SEARCH RECORD");
	outtextxy(150,175,"4.MODIFY RECORD");
	outtextxy(150,200,"5.DELETE RECORD");
	outtextxy(150,225,"6.REPORT ");
	outtextxy(150,250,"7.EXIT FROM MENU");
	outtextxy(150,275,"8.EXIT FROM PROGRAM");
}
void menu4()
{
	cleardevice();
	setbkcolor(1);
	setcolor(3);
	rectangle(0,0,639,479);
	settextstyle(4,0,4);
	outtextxy(160,25,"**TRANSACTION'S-MENU**");
	settextstyle(1,0,2);
	outtextxy(168,75,"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	outtextxy(150,100,"1.ISSUE BOOK");
	outtextxy(150,125,"2.RETURN BOOK");
	outtextxy(150,150,"3.REPORT");
	outtextxy(150,175,"4.EXIT FROM MENU");
	outtextxy(150,200,"5.EXIT FROM PROGRAM");
}
void main()       //MAIN FUNCTION
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");
	int a,t;
	int ctr=0;
	e1:
	char ch1;
	int gd,gm,i,flag;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	char pass[8],pass1[8];
	pass[0]='A';
	pass[1]='T';
	pass[2]='T';
	pass[3]='I';
	pass[4]='T';
	pass[5]='U';
	pass[6]='D';
	pass[7]='E';
	setcolor(DARKGRAY);
	settextstyle(3,0,4);
	setbkcolor(0);
	setcolor(YELLOW+BLINK);
	rectangle(5,5,635,470);
	setcolor(MAGENTA);
	outtextxy(30,10,"WELCOME TO LIBRARY MANAGMENT");
	outtextxy(225,55,"PROGRAM");
	settextstyle(4,0,2);
	setcolor(MAGENTA);
	outtextxy(390,300,"Created By :");
	settextstyle(7,0,2);
	setcolor(BROWN);
	outtextxy(390,330,"S.Rakendu Rajvallabh ");
	outtextxy(390,360,"Mayur Raj Sharma ");
	outtextxy(390,390,"Siddhant Duttagupta ");
	settextstyle(4,0,2);
	setcolor(CYAN);
	settextstyle(3,0,2);
	setcolor(LIGHTRED);
	outtextxy(100,250,"press any key to continue...");
	getch();
	cleardevice();
	setcolor(10);
	rectangle(5,5,635,470);
	gotoxy(23,8);
	cout<<"PLEASE ENTER YOUR PASSWORD";
	gotoxy(30,10);
	for(i=0;i<8;i++)
	{
		pass1[i]=getch();
		cout<<'*';
	}
	rectangle(5,5,635,470);
	getch();
	for(i=0;i<8;i++)
	{
		if(pass1[i]==pass[i])
		{
			flag =0;
		}
		else
		if(pass1[i]!=pass[i])
		{
			flag=1;
			ctr=ctr+1;
			if(ctr==2)
			{
				exit(0);
			}
			break;
		}
	}
	if(flag==1)
	{
		rectangle(5,5,635,470);
		gotoxy(25,13);
		cleardevice();
		rectangle(5,5,635,470);
		cout<<"WRONG PASSWORD";
		delay(1500);
		goto e1;
	}
	else
	if(flag==0)
	{
		rectangle(5,5,635,470);
		gotoxy(20,6);
		cleardevice();
		rectangle(5,5,635,407);
		cout<<"PLEASE WAIT..";
		gotoxy(20,7);
		for(i=0;i<16;i++)
		{
			delay(40);
		}
	}
	while(1)
	{
		menu();
		outtextxy(150,280," ENTER YOUR CHOICE ");
		gotoxy(60,20);
		cin>>a;
		switch(a)
		{
			case 1:menu2();
					 outtextxy(150,300," ENTER YOUR CHOICE ");
					 gotoxy(70,20);
					 cin>>t;
					 if(t==1)
					 {
						addrec();
						getch();
						break;
					 }
					else if(t==2)
					{
						disprec();
						getch();
						break;
					}
					else if(t==3)
					{
						srec();
						getch();
						break;
					}
					else if(t==4)
					{
						modify();
						getch();
						break;
					}
					else if(t==5)
					{
						delrec();
						getch();
						break;
					}
				  else if(t==6)
					{
						streport1();
						getch();
						break;
					}
					else if(t==7)
					{
						break;
					}
					else if(t==8)
					{
						exit(0);
					}
			case 2:menu3();
					 outtextxy(150,300," ENTER YOUR CHOICE ");
					 gotoxy(70,20);
					 cin>>t;
					 if(t==1)
					 {
						addition_rec();
						getch();
						break;
					 }
					 else if(t==2)
					 {
						display_rec();
						getch();
						break;
					 }
					 else if(t==3)
					 {
						search_rec();
						getch();
						break;
					 }
					 else if(t==4)
					 {
						modification();
						getch();
						break;
					 }
					 else if(t==5)
					 {
						memdel();
						getch();
						break;
					 }
					 else if(t==6)
					 {
						memreport1();
						getch();
						break;
					 }
					 else if(t==7)
					 {
						break;
					 }
					 else if(t==8)
					 {
						exit(0);
					 }
			case 3:menu4();
				 outtextxy(150,280," ENTER YOUR CHOICE ");
				 gotoxy(60,20);
				 cin>>t;
					 if(t==1)
					 {
						issue();
						getch();
						break;
					 }
					else if(t==2)
					{
						return_book();
						getch();
						break;
					}
					else if(t==3)
					{
						tr_report();
						getch();
						break;
					}
					else if(t==4)
					{
						break;
					}
					else if(t==5)
					{
						exit(0);
					}
			case 4: exit(0);
		 }
	}
}
