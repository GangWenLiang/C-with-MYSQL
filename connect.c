#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

static char *host = "localhost";
static char *user = "root";
static char *pass = "k100k100";
static char *dbname = "test";
static int port = 3306;//can find using terminal nano /ect/mysql/my.cnf
static char *unix_socket = NULL;//connection type
static int flag = 0;

int main()
{
	MYSQL *conn;
	conn = mysql_init(NULL);
	if(!(mysql_real_connect(conn,host,user,pass,dbname,port,unix_socket,flag)))
	{
		//mysql_real_connect function 
		//	return 0 if successful 
		//	else not 0 error ocurred;
		fprintf(stderr, "\nError: %s [%d]\n",mysql_error(conn),mysql_errno(conn));
		exit(1);
	}
	printf("connection successful\n");

}	return 0;