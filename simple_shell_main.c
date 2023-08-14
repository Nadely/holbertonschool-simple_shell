#include <unistd.h>
#include <string.h>
void faire_quelque_chose()
{

}
int main(void)
{
	const int buffer_size = 1024;
	char buffer[buffer_size];
	char path[buffer_size];

	while (1)
	{
		getcwd(path, buffer_size);
		strcat(path, "$ ");
		write(1, path, strlen(path));
		read(0, buffer, buffer_size);
		faire_quelque_chose();
	}
}
