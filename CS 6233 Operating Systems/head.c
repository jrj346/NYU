#include "types.h"
#include "stat.h"
#include "user.h"


char buf[5000];

/////////////////////////////////////////////////
void
head0(int fd , char *name)
{
  int i , n;
  int l; //number of lines 

  l = 0;

i=0;
n = read(fd, buf, sizeof(buf));
//printf(1, "%d\n\n", n);
while((l < 10 ) && ( i < 1024)){//&& l < 10 ){
    //i++;
    printf(1, "%c", buf[i]);
i++;
    if(buf[i] == '\n'){// && buf[i-1] != ' ' || buf[i] == '\t'){
        l++;
//	printf(1, "%d\n", l);
        if (buf[i+1] == '\n'){
		l--;
	
	}
	
     }
 
  }
  if(n < 0){
    printf(1, "wc: read error\n");
    exit();
  }
 // printf(1," %s\n", name);
//printf(1, "%s    %d\n", buf, l);


//printf(1, "hello world");
}
/////////////////////////////////////////////////////
void
head1(int fd , char *lines)
{


  int i , n;
  int l; //number of lines 

  l = 0;
 int limits = 0;

if (lines[0] == '-') lines++;
limits = atoi(lines);

printf(1, "%d\n\n", limits);

i=0;
n = read(fd, buf, sizeof(buf));
//printf(1, "%d\n\n", n);
while((l < limits ) && ( i < 1024)){//&& l < 10 ){
    //i++;
    printf(1, "%c", buf[i]);
i++;
    if(buf[i] == '\n'){// && buf[i-1] != ' ' || buf[i] == '\t'){
        l++;
 //       printf(1, "%d\n", l);
        if (buf[i+1] == '\n'){
                l--;

        }

     }

  }
  if(n < 0){
    printf(1, "wc: read error\n");
    exit();
  }
  //printf(1," %s\n", limits);
//printf(1, "%s    %d\n", buf, l);


//printf(1, "hello world");
}



////////////////////////////////////////////////////////
void
head2(int fd , char *name)
{
int n, i,l;

n =  read(0, buf, 1024 * sizeof(char));
i =l = 0;

while((l < 10 ) && ( i < 1024)){//&& l < 10 ){
    //i++;
    printf(1, "%c", buf[i]);
i++;
    if(buf[i] == '\n'){// && buf[i-1] != ' ' || buf[i] == '\t'){
        l++;
//      printf(1, "%d\n", l);
        if (buf[i+1] == '\n'){
                l--;

        }

     }

  }
  if(n < 0){
    printf(1, "wc: read error\n");
    exit();
  }

}


////////////////////////////////////////////////////////////////////////////
int
main(int argc, char *argv[])
{
  int fd, i;//,l;

//-----------------read from standard input----------
  if(argc <= 1){
head2(0, "");

//printf(1, "this is standard input");


    exit();
  }//with no arguments 
//----------------extending head---------------- 
if (argc == 3){

//for(i = 1; i < argc; i++){
    if((fd = open(argv[2], 0)) < 0){
      printf(1, "cannot open extended %s\n", argv[2]);
      exit();
    }
    head1(fd, argv[1]);

    exit();
  }// with 3 arguments  
//-----------------not extending---------------
if (argc == 2){
  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cannot open non-extended%s\n", argv[i]);
      exit();
    }
    head0(fd, argv[i]);
    close(fd);
  }
  exit();
  }//with one arguments
  
  else {exit();}


}

