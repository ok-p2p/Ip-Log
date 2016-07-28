#include "containAlph.h"
#include "LogManage.h"
#include <iostream>

#include <netdb.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

LogManage Log( LOG_DEBUG, 10*1024*1024, "./../log/", "p2pServer" );

int main()
{
	string str1 = "172.23.140.140";
	string str2 = "www.baidu.com";
	string str3 = "mrs.oristartech.cn";
	
	struct hostent *h;
	
	if( ContainAlpha(str1) )
  {
     if( ( h = gethostbyname( str1.c_str() ) ) != NULL )
     {
          str1 = inet_ntoa(*((struct in_addr *)h->h_addr));
     }
     else
     {
        Log.WriteLog(LOG_ERROR, "gethostbyname error~~!\n" );
        cout << "error1" << endl;
     }
  }
  
  if( ContainAlpha(str2) )
  {
     if( ( h = gethostbyname( str2.c_str() ) ) != NULL )
     {
          str2 = inet_ntoa(*((struct in_addr *)h->h_addr));
     }
     else
     {
        Log.WriteLog(LOG_ERROR, "gethostbyname error~~!" );
        cout << "error2" << endl;
     }
  }
  
   if( ContainAlpha(str3) )
  {
     if( ( h = gethostbyname( str3.c_str() ) ) != NULL )
     {
          str3 = inet_ntoa(*((struct in_addr *)h->h_addr));
     }
     else
     {
        Log.WriteLog(LOG_ERROR, "gethostbyname error~~!" );
        cout << "error2" << endl;
     }
  }
  
  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;
  
  return 0;
}

/*
if( param.ftpIP == string("mrs.oristartech.cn") )
{
	numIP = "119.10.114.98";
}

if( ContainAlpha(numIP) )
{
   if( ( h = gethostbyname( numIP.c_str() ) ) != NULL )
   {
        numIP = inet_ntoa(*((struct in_addr *)h->h_addr));
   }
   else
   {
      Log.WriteLog(LOG_ERROR, "gethostbyname error~~!" );
   }
}
*/
