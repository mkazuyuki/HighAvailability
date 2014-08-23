#include <unistd.h>
#include <time.h>
#include <sys/select.h>

enum {
	MSG_VOTE_REQUEST,
	MSG_VOTE_REPLY,
	MSG_HB_REQUEST,
	MSG_HB_REPLY
};

enum { FOLLOWER, CANDIDATE, LEADER };

struct msg {
	int	node;
	int	content;
};

#ifndef EXTERN
extern int	ID;
extern char	MYADDR[];
extern char*	destaddr[3];
extern int	destport[]; 
extern int	PORT;
extern int	TIMEOUT;
extern int	sd;
extern struct	sockaddr_in	addr;
extern fd_set	fds, readfds;
extern int	maxfd;
extern char	buf[1024];
extern int	role;
extern int	NUMNODE;
#else

//char	MYADDR[] = "127.0.0.1";
int	ID;
int	NUMNODE;
char*	destaddr[] = {
	"127.0.0.1",
	"127.0.0.1",
	"127.0.0.1"
};

int	destport[] = {
	11111,
	11112,
	11113
};

//int	PORT	= 11110;
int	TIMEOUT	= 6;
int	sd;
struct	sockaddr_in	addr;
fd_set	fds, readfds;
int	maxfd;
//char	buf[1024];

int	role = FOLLOWER;

#endif

int init_raft(char*);

// follower.c
int follower(void);
int hbrecv(void);

// candidate.c
int candidate(void);
int request_vote(void);
int candidate_recv(void);

// leader.c
int leader(void);