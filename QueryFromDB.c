#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

static char *host = "localhost";
static char *user = "root";
static char *pass = "password";
static char *dbname = "test";
static int port = 3306;//can find using terminal nano /ect/mysql/my.cnf
static char *unix_socket = NULL;//connection type
static int flags = 0;

int main()
{
	MYSQL *conn;
	
	MYSQL_RES *res;
	MYSQL_ROW row;

	conn = mysql_init(NULL);
	if(!(mysql_real_connect(conn,host,user,pass,dbname,port,unix_socket,flags)))
	{
		//mysql_real_connect function 
		//	return 0 if successful 
		//	else not 0 error ocurred;
		fprintf(stderr, "\nError: %s [%d]\n",mysql_error(conn),mysql_errno(conn));
		exit(1);
	}
	printf("connection successful\n");
	
	//FORM HERE DOWN DIFFERENT!
	printf("%s\t%s\t%s\n","ID","Name","Date Created");
	
	mysql_query(conn, "SELECT * FROM User");
	res = mysql_store_result(conn);
	while(row = mysql_fetch_row(res))
	{
		printf("%s\t%s\t%s\n",row[0],row[2],row[1]);
	}

	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}