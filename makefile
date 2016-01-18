CCFLAG=-L"D:\\bin\\Dev-Cpp\\MinGW32\\include\\" -L"D:\\bin\\Dev-Cpp\\MinGW32\\mingw32\\include\\"  -L"D:\\bin\\Dev-Cpp\\MinGW32\\lib\\gcc\\mingw32\\4.8.1\\include\\" -L"D:\\bin\\Dev-Cpp\\MinGW32\\lib\\gcc\\mingw32\\4.8.1\\include\\c++\\"
TARGET:filterFileVersion svnUpdate cvsCommit copyBySource executeCmd ftpFiles
filterFileVersion:filterFileVersion.o fileVersion.o
	g++ $(CCFLAG) -o d:/bin/$@ $^
svnUpdate:svnUpdate.o fileVersion.o
	g++ $(CCFLAG) -o d:/bin/$@ $^
cvsCommit:cvsCommit.o fileVersion.o
	g++ $(CCFLAG) -o d:/bin/$@ $^
copyBySource:copyBySource.o fileVersion.o pathTools.o
	g++ $(CCFLAG) -o d:/bin/$@ $^
executeCmd:executeCmd.o
	g++ $(CCFLAG) -o d:/bin/$@ $^
ftpFiles:ftpFiles.o fileVersion.o pathTools.o
	g++ $(CCFLAG) -o d:/bin/$@ $^

clean:
	rm *.o
