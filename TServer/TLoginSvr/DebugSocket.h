class CDebugSocket 
{
public:
	CDebugSocket();
	~CDebugSocket();

private: 
	SOCKET				m_SendSock;
	SOCKADDR_IN			m_siAddr;
	CRITICAL_SECTION	m_DebugLock;

	VOID CLOSESOCKET( SOCKET &x )	{	if(x != INVALID_SOCKET) closesocket(x), x = INVALID_SOCKET; }

public:
	BOOL Initialize(char *pIPAddr, int pPort);
	void LogLogin(CTUser *pUser, DWORD dwUserID);
	void LogInvalidPacket(char* szIP);

private:
	void SendToTerminal(char *szData);

};