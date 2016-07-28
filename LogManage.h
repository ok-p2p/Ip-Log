/**
 * @file LogManager.h
 * @brief logger header file
 *
 *
 * @author xiehua@ceopen.cn
 * @version 1.0
 * @date 2009-05-10
 *
 */
 
 //@author wangzhongping@oristartech.com
 //@date 2012-7-26
 //Add SetLogLevel(); GetLogLevel(); SetLogPath();
 //

#ifndef __LOGMANAGE__H__
#define __LOGMANAGE__H__


#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#define MAX_DIR_LENGTH 128
#define MAX_TIMESTRING_LENGTH 20
#define MAX_LOGFILE_FULLPATH_LENGTH 128
#define MAX_BASE_LOGNAME_LEN 16

#define LOG_FAIL	-1
#define LOG_OK		0

#define LOG_DEBUG	0
#define LOG_INFO	1
#define LOG_ERROR	2
#define LOG_FATAL	3


class LogManage
{
public:
	LogManage(int inLevel, int inMaxLogFileSize, const char *inLogDir, const char *inBaseLogName);
	~LogManage();

	void WriteLog(int logLevel, const char *inLogContent);

	//void WriteToLog(string inLogData, SInt32 logLevel);

	//log rolls automatically based on the configuration criteria,
	//but you may roll the log manually by calling this function.
	//Returns true if no error, false otherwise
	int  RollLog();
	int CheckRollLog();

	//
	// Call this to open the log file and begin logging
	int EnableLog();

	// Call this to close the log
	// (pass leaveEnabled as true when we are temporarily closing.)
	void CloseLog();

	static	char *logLevelStr[];

	static	char *logMsgString[];
	
	//Add by wangzhongping@oristartech.com
	//动态设置日志级别。
	void SetLogLevel(int iLevel)
	{
		m_logLevel = iLevel;
	}
	//Add by wangzhongping@oristartech.com
	int GetLogLevel()
	{
		return m_logLevel;
	}
	//Add by wangzhongping@oristartech.com
	//运行时设置日志的存放路径。由上层程序控制线程安全
	int SetLogPath(const char *strLogPath);
	
	
	

protected:
private:

	FILE*	m_pFile;
	char	m_logCreateTime[MAX_TIMESTRING_LENGTH];
	char	m_logFullPath[MAX_LOGFILE_FULLPATH_LENGTH];
	//Mutex	m_fMutex;

	volatile int		 m_logLevel;
	char	 m_logDir[MAX_DIR_LENGTH];
	char	 m_baseLogName[MAX_BASE_LOGNAME_LEN];
	int		 m_maxLogFileSize;

	//char* GetLogName();
	//char* GetLogDir();

	int	RenameLogFile(const char* inFileName);
	//Bool16	DoesFileExist(const char *inPath);
	//char*	GetLogPath(char *extension);
	int	ft_fPrintf(const char *fmt, ...);

};

#endif

