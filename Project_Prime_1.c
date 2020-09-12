/*======================================================================
\Program for calculate and access big primes efficiently and an advanced\
\approach.                                                              \
\                                                                       \
\Code by -- Apratim Sarkar                                              \
\Author-- Apratim Sarkar                                                \
\Planning and designing -- Apratim Sarkar                               \
=========================================================================*/

//library files
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>
#ifdef _WIN32
#include<windows.h>
#include<conio.h>
//#else
//#include<term.h>
#endif

#define s 68719476720
#define mx 2000000000
#pragma loop_opt(on)
typedef unsigned int ui;
typedef unsigned long long ull;
ull n,check1=0;
bool ct=1;
//random facts
char facts[10][200]={"In his 1985 book Contact, Carl Sagan claimed that aliens are" 
					" trying to\n\n   communicate with humans by"
					" using prime numbers as signals.","The largest prime number found so far has"
					" 24,862,048 digits.","Prime numbers protect us from"
					" cybercrime.","The Sieve of Erastothenes was the earliest method of"
					" finding prime numbers.","The worlds most liked number is a prime"
					" number-->7.","Thai people laugh in prime numbers.The Thai word for"
					" 5 is ha,\n\n   which explains all the 555s in Thai forums. ","While the term prime number"
					" refers to prime positive integers,\n\n   other types of primes are also defined,"
					" such as the Gaussian primes.","There is an"
					" organization (GIMPS) dedicated to finding the largest"
					" prime numbers.","Prime numbers get more rare as numbers"
					" get bigger.","No prime number greater than 5 ends in"
					" a 5."
					};

//Pause function
static inline void pse(void)
{
	#ifdef _WIN32
		printf("\n\t\t");
		system("pause");
	#else
    	printf("\n\t\tPress Enter to continue...\n\n");
    	while(getchar()!='\n');
    	fflush(stdin);
    #endif
}

//modified gets function
static inline int getstr(int N,char arr[])
{
	int c,i=0;
	c=getchar();
	while(c!='\n'&&c!=EOF&&i<N)
	{ 
   		arr[i]=c;
   		c=getchar();
   		i++;
	}
	arr[i]='\0';
	fflush(stdin);// in case the user given more inputs than the array size
	return i;
}
//function to check a natural number prime or not
static inline ui pri(ull n)
{
	register ull i;
	ui b=sqrt(n);
	bool k=1;
	if(n%2==0&&n>2)
	{
		return 0;
	}
	else if(n%3==0&&n>3)
	{
		return 0;
	}
	else
	{
		for(i=3;i<=b;i=i+2)
		{
			if(n%i==0)
			{
				k=0;
				break;
			}
		}
		return k;
	}
}	
//prime counting function
static inline ui cnt(const ui c)
{	
	register ui j,a=1,k1;
	if(c==2)
	{
		return 3;
	}
	else
	{
		a=3;
		for(j=5;a<=c;j=j+2)
		{
			if(pri(j))
			{
				++a;
			}
		}
		return j-2;
	}
}
//function for multiplying two numbers
static inline ull rus(ull a,ull b)
{
	ull res=0;
	while(b>0)
	{
		if(b&1)
		{
			res=res+a;
		}
		a=a<<1;
		b=b>>1;
	}
	return res;
} 
//function to calculate nth prime
static inline void nthp(void)
{
	bool *sieve,ct=true;
	ui count=1;
	register ull i,j,p,q;
	menu:
		#ifdef _WIN32
			system("color cf");
		#else
			printf("\033[97;45m"); 
		#endif
		printf("\n\t_______________________________________");
		printf("\n\t|                                     |");
		printf("\n\t| Program to calculate the nth prime. |");
		printf("\n\t|                                     |");
		printf("\n\t| Enter 0 to return to Main Page.     |");
		printf("\n\t|_____________________________________|\n");
		printf("\n\tEnter the value of n:");
		char *arr,*ptr;
		arr=malloc(20*sizeof(char));
		getstr(20,arr);
	if(strcmp("0",arr)!=0)
	{
		for(q=0;arr[q]!='\0';q++)
		{
			if(!isdigit(arr[q]))
			{
				ct=false;
				break;
			}
		}
		if(ct)
		{
			ull n=strtoull(arr,&ptr,10);
			clock_t t=clock();
			if(n==1)
			{
				printf("\n\tThe 1st prime no. is-->2\n\n\tIt is the only Even Prime...!!!\n\n\t");
			}
			else if(n>580000000||n<=0)
			{
				#ifdef _WIN32
					system("color 4e");
				#else
					printf("\033[48;2;255;0;0m");
				#endif
					printf("\n\n\tOut of range...!!! :(\n\n\n\t\a");
					goto menu1;
			}
			else
			{
				if(n<150000)
				{
					#ifdef _WIN32
						system("color 5f");
					#endif
					printf("\n\n\tThe %lluth prime no. is-->%u\n\n",n,cnt(n));
					t=clock()-t;
					printf("\n\tIt took %f seconds.\n\n\t",((float)t)/CLOCKS_PER_SEC);
				}
				else
				{
					ui k1=log(n)+log(log(n));
					ull k=rus(k1,n)+3;
					ui b=sqrt(k)+1;
					k=(k-1)>>1;
					b=(b>>1)-1;
					ull k2=k+(k>>2);
					sieve=malloc(k2*sizeof(bool));
    				for(i=0;i<b;++i)
    				{
    					if(!sieve[i])
    					{
    						++count;
    						for(j=(rus(i,i+3)<<1)+3,p=(i<<1)+3;j<k;j=j+p)
    						{
    							sieve[j]=true;
    						}
    					}
    				}
    				for(p=b;count<n;++p)
    				{
    					if(!sieve[p])
    					{
    						++count;
    					}
    				}
				t=clock()-t;
    				#ifdef _WIN32
						system("color 5f");
					#endif
   					printf("\n\n\tThe %lluth prime no. is-->%llu\n\n",n,(p<<1)+1);
					printf("\n\tIt took %f seconds.\n\n\t",((float)t)/CLOCKS_PER_SEC);
					memset(sieve,0,sizeof(*sieve));
					free(sieve);
				}
			}
			free(arr);
			pse();
		}
		else
		{
			#ifdef _WIN32
				system("color 4e");
			#else
				printf("\033[48;2;255;0;0m");
			#endif
			printf("\n\n\tInvalid input..!!\n\n\tPlease enter a Natural Number...:)\n\n\t\a");
			menu1:
				free(arr);
				ct=true;
				pse();
				system("cls||clear");
				goto menu;
		}
	}
	else
	{ 
		free(arr);
	}
}

//function to calculate number of primes upto n
static inline void phi(void)
{
	bool *sieve1,ct=true;
	register ull c,d,q,i;
	ull o=0,pr,ca=1;
	menu:	
		#ifdef _WIN32
			system("color 3f");
		#else
			printf("\033[35;107m"); 
		#endif
		printf("\n\t___________________________________________________");
		printf("\n\t|                                                 |");
		printf("\n\t|  Program to calculate number of primes upto n.  |");
		printf("\n\t|                                                 |");
		printf("\n\t|  Enter 0 to return to Main Page.                |");
		printf("\n\t|_________________________________________________|\n");
		printf("\n\tEnter the value of n:");
		char *arr,*ptr;
		arr=malloc(20*sizeof(char));
		getstr(20,arr);
	if(strcmp("0",arr)!=0)
	{
		for(q=0;arr[q]!='\0';q++)
		{
			if(!isdigit(arr[q]))
			{
				ct=false;
				break;
			}
		}
		if(ct)
		{
			ull e=strtoull(arr,&ptr,10);
			clock_t t=clock();
			if(e==1||e==2)
			{
				printf("\n\n\tThere are no primes.\n\n\t");
			}
			else if(e>mx||e<=0)
			{
				#ifdef _WIN32
					system("color 4e");
				#else
	    			printf("\033[48;2;255;0;0m");
				#endif
				printf("\n\n\tOut of range...!!! :(\n\n\n\t\a");goto menu1;
			}
			else
			{
				if(e>=2000000)
				{
					sieve1=malloc(e*sizeof(bool));
					for(c=3;c<e;c=c+2)
					{
						if(!sieve1[c])o=o+1;
						for(d=(c*c);d<e;d=d+c)
						{
							sieve1[d]=true;
							t=clock()-t;
						}
					}
					#ifdef _WIN32
						system("color e5");
					#endif
					printf("\n\n\tThere are %llu primes in between 1 to %llu..!!\n\n",o+1,e);
					printf("\n\tIt took %f seconds.\n\n\t",((float)t)/CLOCKS_PER_SEC);
					memset(sieve1,0,sizeof(*sieve1));
					free(sieve1);
				}
				else
				{
					for(i=3;i<e;i+=2)
					{
						if(pri(i))
						{
							++ca;
						}
					}
					t=clock()-t;
					#ifdef _WIN32
						system("color e5");
					#endif
					printf("\n\n\tThere are %llu primes in between 1 to %llu..!!\n\n",ca,e);
					printf("\n\tIt took %f seconds.\n\n\t",((float)t)/CLOCKS_PER_SEC);
				}
			}
			free(arr);
			pse();
		}
		else
		{
			#ifdef _WIN32
				system("color 4e");
			#else
				printf("\033[48;2;255;0;0m");
			#endif
			printf("\n\n\tInvalid input..!!\n\n\tPlease enter a Natural Number...:)\n\n\t\a");
			menu1:
				free(arr);
				ct=true;
				pse();
				system("cls||clear");
				goto menu;
		}
	}
	else
	{ 
		free(arr);
	}
}

//function to represent Fundamental Theorem of Arithmetic
static inline void prime(ull n)
{
	if(pri(n))
    {
    	#ifdef _WIN32
    		system("color 2e");
    	#endif
    	printf("\n\n\tSo the given number %llu is a prime number..!!\n\n\n\t",n);
    }
    else
    {
    	ull *arr1;
    	arr1=malloc(20*sizeof(ull));
    	register ui check1=0,k=0,z,b2=sqrt(n),count=0,c;
    	ull i;
    	for(i=2;i<=n/2;i++)
    	{
    		if(n%i==0)
    		{
    			check1++;
    			if(pri(i))
    			{
    				arr1[k]=i;
    				k++;
    			}
    		}
    	}
    	arr1[k]=n;
    	check1++;
    	#ifdef _WIN32
    		system("color 2e");
    	#endif
    	printf("\n\t>The smallest prime divisor of %llu is %llu.\n",n,arr1[0]);
		printf("\n\t>The largest prime divisor of %llu is %llu.\n",n,arr1[k-1]);
    	printf("\n\n\t|>>There are %u no. of positive divisors of the number %llu..!!\n\n",check1+1,n);
    	for(z=0;z<k;z++)
    	{
        	for(c=1;c<=b2;c++)
        	{
        		if(arr1[z]<INT_MAX)
        		{
        			ull b=pow(arr1[z],c);
        			if(n%b==0)
        			{
        				count++;
        			}
        			else
        			{ 
        				break;
        			}
        		}
        		else
        		{
        			count=1;
        		}
        	}
        	printf("\n\tThe Power of the no.%u prime divisor %llu  is %u in %llu.\n",z+1,arr1[z],count,n);
        	count=0;
    	}
    	printf("\n\n");
    	memset(arr1,0,sizeof(*arr1));
    	free(arr1);
    }
}

//main function 
int main(void)
{
	system("cls||clear");
	#ifdef _WIN32
		system("color 1f");
		printf("WINDOWS");
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize=sizeof cfi;
    	cfi.nFont=0;
   		cfi.dwFontSize.X=14;
	    cfi.dwFontSize.Y=32;
    	cfi.FontFamily=FW_MEDIUM;
    	cfi.FontWeight=600;
		wcscpy(cfi.FaceName,L"NSimSun");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,&cfi);
		ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
		HWND hWnd = GetConsoleWindow();
    	SetConsoleTitle("                                                                                                                                                                                                           ~~Project Prime~~");
    	SetWindowLong(hWnd,GWL_EXSTYLE,
    	GetWindowLong(hWnd,GWL_EXSTYLE)|WS_EX_LAYERED);
    	SetLayeredWindowAttributes(hWnd,0,235,LWA_ALPHA);
	#elif __linux__
    	printf("\033[97;44m"); //setupterm(NULL,__FILE__, NULL);putp(enter_bold_mode);
    	printf("\n\n\tThis is Linux OS...!!!\n\n\n");
    	pse();
    	system("cls||clear");
	#elif __unix__
		printf("\n\n\tOther unix OS...!!!\n\n\n");
		pse();
		system("cls||clear");
	#else
	    printf("\n\n\tUnidentified OS\n\n\n");
    	pse();
    	system("cls||clear");
	#endif
	char choice[20];
	register int q;
	bool ct1=true;
	Menu:
		#ifdef _WIN32
			system("color 1f");
		#else
			printf("\033[97;44m");
			//system("setterm -bold on");
		#endif
		printf("\n\t\t____________________________________________________________");
		printf("\n\t\t||                                                        ||");
		printf("\n\t\t||  Welcome to the world of Prime positive integers...!!  ||");
		printf("\n\t\t||________________________________________________________||\n");
		printf("\n\t\t|>  A natural number p>1 is said to be a prime, \n");
		printf("\n\t\t    if its only positive divisors are 1 and p.\n");
		printf("\n\t\t|>> There are infintely many primes...!!!\n");
		printf("\n\t\t____________________________________________________________");
		printf("\n\t\t|                                                          |");
		printf("\n\t\t| 1.Enter 1 to find nth prime p(n).                        |");
		printf("\n\t\t|                                                          |");
		printf("\n\t\t| 2.Enter 2 to find number of primes upto n. phi(n)        |");
		printf("\n\t\t|                                                          |");
		printf("\n\t\t| 3.Enter 3 to implement Fundamental Theorem of Arithmetic.|");
		printf("\n\t\t|                                                          |");
		printf("\n\t\t| 4.Enter 4 to EXIT the Portal...                          |");
		printf("\n\t\t|__________________________________________________________|\n");
		printf("\n\t\t>>Enter your choice:");
		getstr(20,choice);
		fflush(stdin);
		system("cls||clear");

	if(strcmp("1",choice)==0)
	{
		nthp();
		system("cls||clear");
		goto Menu;
	}
	else if(strcmp("2",choice)==0)
	{
		phi();
		system("cls||clear");
		goto Menu;
	}
	else if(strcmp("3",choice)==0)
	{
		menu22:
			#ifdef _WIN32
				system("color f2");
			#else
				printf("\033[33;40m"); 
			#endif 
			printf("\n\t__________________________________________________________________");
			printf("\n\t|                                                                |");
			printf("\n\t| Program to represent the ~~FUNDAMENTAL THEOREM OF ARITHMETIC~~ |");
			printf("\n\t|                                                                |");
			printf("\n\t| Enter 0 to return to Main Page.                                |");
			printf("\n\t|________________________________________________________________|\n");
			printf("\n\t______________________________________________________________________");
			printf("\n\t| ||O>Theorem-->                                                     |");
			printf("\n\t| ============                                                       |");
			printf("\n\t| If n is a natural number, it can be uniquely written as a product  |");
			printf("\n\t|                                                                    |");
			printf("\n\t|               e1   e2         ek                                   |");
			printf("\n\t| of primes:n=(p1 X p2  X ...X pk ), where (p1,p2,...,pk) is the     |");
			printf("\n\t|                                                                    |"); 
			printf("\n\t| set of prime divisors of n and (e1,e2,...,ek) is the set of        |");
			printf("\n\t|                                                                    |");
			printf("\n\t| exponents of the respective prime divisors.                        |");
			printf("\n\t|____________________________________________________________________|");
			printf("\n\n\n\tEnter a NATURAL number : ");
			char *arr3,*ptr;
			arr3=malloc(20*sizeof(char));
			getstr(20,arr3);
			system("cls||clear");
		if(strcmp("0",arr3)!=0)
		{
			for(q=0;arr3[q]!='\0';q++)
			{
				if(!isdigit(arr3[q]))
				{
					ct1=false;
					break;
				}
			}
			if(ct1)
			{
				ull n=strtoull(arr3,&ptr,10);
				clock_t t=clock();
				if(n>s||n<=0)
				{
					#ifdef _WIN32	
						system("color 4e");
					#else
			        	printf("\033[48;2;255;0;0m");
					#endif
					printf("\n\n\tOut of range...!!! :(\n\n\n\t\a");
					goto menu3;
				}
				else if(n==1)
				{
					printf("\n\n\t1 is neither prime nor composite number.\n\n\t");
				}
				else
				{ 
					prime(n);
				}
				t=clock()-t;
				printf("\n\tIt took %f seconds.\n\n\t",((float)t)/CLOCKS_PER_SEC);
				free(arr3);
				pse();
			}
			else
			{
				#ifdef _WIN32
					system("color 4e");
				#else
			   		printf("\033[48;2;255;0;0m");
				#endif
				free(arr3);
				printf("\a\n\n\tInvalid input..!!\n\n\tPlease enter a natural number...:)\n\n\t");
				menu3:
					ct1=true;
					pse();
					system("cls||clear");
					goto menu22;
			}
		}
		system("cls||clear");
		goto Menu;
	}
	else if(strcmp("4",choice)==0)
	{
		#ifdef _WIN32
			system("color f1");
		#else
			printf("\033[39;49m");
		#endif
		printf("\n\n");
		printf("\t\t\t________________________________________\n");
		printf("\t\t\t|                                      |\n");
		printf("\t\t\t|   Thanks for visiting :)   !!!       |\n");
		printf("\t\t\t|______________________________________|\n\n");
		srand(time(0));
		int ran=rand()%10;
		printf("\n|->Amazing fact about Prime Numbers:\n\n   ");
		printf("%s\n\n\t",facts[ran]);
		printf("\n\t\t# For any futher questions or suggestions please write at\n");
		printf("\n\t\t||--> apratimsarkar13031999@gmail.com ");
		printf("\n\t\t     -------------------------------");
		time_t ti;
		time(&ti);
		printf("\n\n\t\t%s\n\n\t\t",ctime(&ti));
		pse();
		system("cls||clear");
		#ifdef _WIN32
			system("color 0f");
		#else
			printf("\033[39;49m");
		#endif
		exit(0);
	}
	else
	{
		#ifdef _WIN32
			system("color e4");
		#else
			printf("\033[48;2;255;0;0m");
		#endif
		printf("\n\n\n");
		printf("\t\t\t________________________________________\n");
		printf("\t\t\t|                                      |\n");
		printf("\t\t\t| You have entered an wrong input!  :( |\n");
		printf("\t\t\t|                                      |\n");
		printf("\t\t\t|   Please enter between 1 to 4...  :) |\n");
		printf("\t\t\t|______________________________________|\n\a");
		printf("\n\n\t");
		srand(time(0));
		int ran1=rand()%10;
		printf("\n|->Amazing fact about Prime Numbers:");
		printf("\n===================================\n\n   ");
		printf("%s\n\n\n\t",facts[ran1]);
		fflush(stdin);
		pse();
		system("cls||clear");
		goto Menu;
	}
	return 0;
}
