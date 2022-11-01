#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void checkInfoQR(){
    char code[60];
    scanf("%s", code);
    char X[5];
    char account[20];
    char *find;
    char day[4];
    char month[4];
    char year[5];
    char date[10];
    char bank1[5]="BKB";
    char bank2[5]="KHB";
    char bank3[5]="HBB";
    int i ;
    int length=strlen(code);
	if (find=strstr(code,bank1))
	{
        strncpy( X, find+0, 3 );
        printf("Ngan hang: %.3s\n",X);
        strncpy( account, code+14, 13 );
        printf("So tai khoan: %.13s\n",account);
        printf("Ten chu tai khoan: ");
        for(i=27; i<length; i++)
          {  if((code[i]>='a'&&code[i]<='z')||(code[i]>='A'&&code[i]<='Z'))
            printf( "%c",code[i]);  }
        strncpy( date, code+(length-8), 8 );
        int length1=strlen(date);
        strncpy( day, date+0, 2);
        strncpy( month, date+2, 2);
        strncpy( year, date+(length1-4), 4);
        printf("\nThoi diem tao QR: %.2s/%.2s/%2s", day, month, year);
	}
    else if (find=strstr(code,bank2))
    {
        strncpy( X, find+0, 3 );
        printf("Ngan hang: %.3s\n",X);
        strncpy( account, code+22, 15 );
        printf("So tai khoan: %s\n",account);
        printf("Ten chu tai khoan: ");
        for(i=37; i<length; i++)
         printf( "%c",code[i]);
        strncpy( date, code+11, 8 );
        strncpy( day, date+2, 2);
        strncpy( month, date+0, 2);
        strncpy( year, date+4, 4);
        printf("\nThoi diem tao QR: %.2s/%.2s/%2s", day, month, year);
    }
    else if (find=strstr(code,bank3))
    {   char account1;
        strncpy( X, find+0, 3 );
        printf("Ngan hang: %.3s\n",X);
        printf("So tai khoan: ");
        for(i=12; i<=length-10; i++)
        {  if(isdigit(code[i]) )
            printf( "%c",code[i]);  }
        printf("\nTen chu tai khoan: ");
        for(i=11; i<=36; i++)
         {  if((code[i]>='a'&&code[i]<='z')||(code[i]>='A'&&code[i]<='Z'))
            printf( "%c",code[i]);  }
        strncpy( date, code+(length-9), 6 );
        strncpy( day, date+4, 2);
        strncpy( month, date+2, 2);
        strncpy( year, date+0, 2);
        printf("\nThoi diem tao QR: %.2s/%.2s/20%.2s", day, month, year);
    }
    else printf("Khong co ngan hang");
}

void toBKB()
{
    char code[60];
    scanf("%s",code);
    int length=strlen(code);
    int i;
    int count =0;
    int n=0;
    char date[10];
    char day[4];
    char month[4];
    char year[5];
    char account[16];
    char name[25];
        for(i=0; i<length; i++)
        {
            if(isdigit(code[i]) )
                count++;
        }
        if(count==34)
        {
            strncpy(account, code+22, 15);
            strncpy( date, code+11, 8);
            strncpy( day, date+2, 2);
            strncpy( month, date+0, 2);
            strncpy( year, date+4, 4);
            for(i=37; i<length; i++)
            {
                if((code[i]>='a'&&code[i]<='z')||(code[i]>='A'&&code[i]<='Z'))
                    n++;
                strncpy(name, code+37,n);
            }
            printf("00020101021KHB%s%s%.2s%.2s%.4s\n",account,name,day,month,year);
            }
        else
        {
            char name1[n];
            strncpy(account,code+(length-17),8);
            strncpy( date, code+(length-9), 6 );
            strncpy( day, date+4, 2);
            strncpy( month, date+2, 2);
            strncpy( year, date+0, 2);
            for(i=11; i<(length-17); i++)
            {
                n++;
            }
            strncpy(name1,code+11,n);
            printf("00020101021HBB%.8s%s%.2s%.2s20%.2s\n",account,name1,day,month,year);
        }
}
void toKHB()
{
    char code[60];
    scanf("%s",code);
    int length=strlen(code);
    int i;
    int count =0;
    int n=0;
    char date[10];
    char day[4];
    char month[4];
    char year[5];
    char account[16];
    char name[25];
    //char falsename[n+1];
        for(i=0; i<=length; i++)
        {
            if(isdigit(code[i]))
                count++;
        }
        if(count==32)
        {
            strncpy( account, code+14, 13 );
            for(i=27; i<length; i++)
            {
                if((code[i]>='a'&&code[i]<='z')||(code[i]>='A'&&code[i]<='Z'))
                    n++;
                strncpy(name ,code+27,n);
            }
            strncpy( date, code+(length-8), 8 );
            int length1=strlen(date);
            strncpy( day, date+0, 2);
            strncpy( month, date+2, 2);
            strncpy( year, date+(length1-4), 4);
            printf("00020101021%.2s%.2s%.4sBKB%.13s%s\n",month,day,year,account,name);
        }
        else
        {
            for(i=11; i<(length-4); i++)
                {
                    if((code[i]>='a'&&code[i]<='z')||(code[i]>='A'&&code[i]<='Z'))
                        n++;
                    strncpy(name ,code+11,n);
                }
        strncpy(account,code+(length-17),8);
        strncpy( date, code+(length-9), 6 );
        strncpy( day, date+4, 2);
        strncpy( month, date+2, 2);
        strncpy( year, date+0, 2);
        printf("00020101021%.2s%.2s20%.2sHBB%.8s%s\n",month,day,year,account,name);
        }
}
void toHBB()
{
    char code[60];
    scanf("%s",code);
    int length=strlen(code);
    int i;
    int count =0;
    int n=0;
    char date[10];
    char day[4];
    char month[4];
    char year[5];
    char account[16];
    char name[25];
        for(i=0; i<=length; i++)
        {
            if(isdigit(code[i]) )
                count++;
        }
        if(count==32)
        {
            strncpy( account, code+14, 13 );
            for(i=27; i<length; i++)
            {
                if((code[i]>='a'&&code[i]<='z')||(code[i]>='A'&&code[i]<='Z'))
                    n++;
                strncpy(name ,code+27,n);
            }
            char falsename[n+1];
        strcpy(falsename,name);
        strncpy( date, code+(length-8), 8 );
        strncpy( day, date+0, 2);
        strncpy( month, date+2, 2);
        strncpy( year, date+6, 2);
        printf("00020101021%s%.13s%.2s%.2s%.2sBKB\n",falsename,account,year,month,day);
        }
        else
        {
            strncpy(account, code+22, 15);
            strncpy( date, code+11, 8);
            strncpy( day, date+2, 2);
            strncpy( month, date+0, 2);
            strncpy( year, date+6, 2);
            for(i=37; i<length; i++)
            {
                if((code[i]>='a'&&code[i]<='z')||(code[i]>='A'&&code[i]<='Z'))
                    n++;
                strncpy(name, code+37,n);
            }
            printf("00020101021%s%s%.2s%.2s%.2sKHB\n",name,account,year,month,day);
        }
}
void convertcode()
{
    char bank[4];
    char bank1[5]="BKB";
    char bank2[5]="KHB";
    char bank3[5]="HBB";
    char code1[60];
    scanf("%s", bank);
    if (strcmp(bank,bank1)==0)
    {
        toBKB();
    }
    else if (strcmp(bank,bank2)==0)
    {
        toKHB();
    }
    else if (strcmp(bank,bank3)==0)
    {
        toHBB();
    }
    else
    {
        scanf("%s",code1);
        printf("Ngan hang chuyen den khong hop le\n") ;
    }
}
int encryptQR() {
	int ename, eaccount, ecode;
	scanf("%d %d %d", &ename, &eaccount, &ecode);
	char code[68];
    scanf("%s", code);
    char *tenNH;
    char Bank1[4] = "BKB";
    char Bank2[4] = "KHB";
    char Bank3[4] = "HBB";
    char VNcode[] = "00020101021";
    char account[16];
    char inaccount[20];
    char name[31];
    char inname[200];
    char date[9];
    char day[3];
    char month[3];
    char year[5];
    char fixcode[200];
    char c[100];
    char temp_string[3];
    int i, k, m, n, temp;
    int index = 0;
    int j = 0; int a = 0; int b = 0; int d = 0;
    int length = strlen(code);
    if ((ename < 0) || (ename >= 3) || (eaccount < 0) || (eaccount >= 2) || (ecode < 0) || (ecode >= 2)) {
    	printf("Thong so nhap vao khong hop le");
    	return 0;
    }
    if (tenNH = strstr(code, Bank1)) {
    	for(i = 27; i < length; i++) {  
	      	if((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z')) {
	            name[j] = code[i];
	            j++;
	        }
	        name[j] = '\0';
		}
    	if (ename == 0) {
    		strcpy(inname, name);
    		inname[strlen(inname)] = '\0';
    	}
	    if (ename == 1) {
	    	for (i = 0; i < strlen(name) ; i++) {
				temp = name[i];
        		sprintf(c,"%d", temp);
        		for (k = 0; k < strlen(c); k++) {
		            inname[a] = c[k];
		            a++;
		        }
	    	}
	    	inname[a] = '\0';
       	}
       	if (ename == 2) {
       		
		    for (i = 0; i < strlen(name); i++) {
				if (name[i] >= 'A' && name[i] <= 'Z') {
					sprintf(temp_string, "%02d", name[i] - 65);
				}
				if (name[i] >= 'a' && name[i] <= 'z') {
					sprintf(temp_string, "%2d", name[i] - 71);
				}
				inname[index] = temp_string[0];				
				inname[index + 1] = temp_string[1];			
				index += 2;
			}
			inname[index] = '\0';
		}
        if (eaccount == 0) {
        	strncpy(inaccount, code + 14, 13);
        	inaccount[strlen(inaccount)] ='\0';
		}
    	else if (eaccount == 1) {
    		strncpy(account, code + 14, 13);
    		for (i = 12; i >= 0; i--) {
    			inaccount[b] = account[i];
    			b++ ;
			}
			inaccount[b] = '\0';
		}
    	strncpy(date , code + (length - 8), 8); 
    }
    else if (tenNH = strstr(code, Bank2)) {
    	for (i = 37; i < length; i++) {  
	      	if((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z')) {
	            name[j] = code[i];
	            j++;
	        }
	        name[j] = '\0';
		}
    	if (ename == 0) {
    		strcpy(inname, name);
    		inname[strlen(inname)] = '\0';
    	}
	    else if (ename == 1) {
	    	for (i = 0; i < strlen(name) ; i++) {
				temp = name[i];
        		sprintf(c,"%d", temp);
        		for (k = 0; k < strlen(c); k++) {
		            inname[a] = c[k];
		            a++;
		        }
	    	}
	    	inname[a] = '\0';
       	}
       	else if (ename == 2) {
		    for (i = 0; i < strlen(name); i++) {
				if (name[i] >= 'A' && name[i] <= 'Z') {
					sprintf(temp_string, "%02d", name[i] - 65);
				}
				if (name[i] >= 'a' && name[i] <= 'z') {
					sprintf(temp_string, "%2d", name[i] - 71);
				}
				inname[index] = temp_string[0];				
				inname[index + 1] = temp_string[1];			
				index += 2;
			}
			inname[index] = '\0';
		}
        if (eaccount == 0) {
        	strncpy(inaccount, code + 22, 15);
        	inaccount[strlen(inaccount)] ='\0';
		}
    	else if (eaccount == 1) {
    		strncpy(account, code + 22, 15 );
    		for (i = 14; i >= 0; i--) {
    			inaccount[b] = account[i];
    			b++ ;
			}
			inaccount[b] = '\0';
		}
    	strncpy(date, code + 11, 8); 
    }
    else if (tenNH = strstr(code, Bank3)) {
    	for (i = 11; i < length - 17; i++) {  
	      	if((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z')) {
	            name[j] = code[i];
	            j++;
	        }
	        name[j] = '\0';
		}
    	if (ename == 0) {
    		strcpy(inname, name);
    		inname[strlen(inname)] = '\0';
    	}
	    else if (ename == 1) {
	    	for (i = 0; i < strlen(name) ; i++) {
				temp = name[i];
        		sprintf(c,"%d", temp);
        		for (k = 0; k < strlen(c); k++) {
		            inname[a] = c[k];
		            a++;
		        }
	    	}
	    	inname[a] = '\0';
       	}
       	else if (ename == 2) {
		    for (i = 0; i < strlen(name); i++) {
				if (name[i] >= 'A' && name[i] <= 'Z') {
					sprintf(temp_string, "%02d", name[i] - 65);
				}
				if (name[i] >= 'a' && name[i] <= 'z') {
					sprintf(temp_string, "%2d", name[i] - 71);
				}
				inname[index] = temp_string[0];				
				inname[index + 1] = temp_string[1];			
				index += 2;
			}
			inname[index] = '\0';
		}
        if (eaccount == 0) {
        	for(i = 12; i < length - 9; i++) {  
            	if(isdigit(code[i])) {
            		inaccount[b] = code[i];
            		b++;
            	}
            }
        	inaccount[b] ='\0';
		}
    	else if (eaccount == 1) {
    		for(i = 12; i < length - 9; i++) {  
            	if(isdigit(code[i])) {
            		account[b] = code[i];
            		b++;
            	}
            }
        	account[b] ='\0';
    		for (i = 7; i >= 0; i--) {
    			inaccount[d] = account[i];
    			d++ ;
			}
			inaccount[d] = '\0';
		}
    	strncpy(date, code + (length - 9), 6 );
    }
    if (ecode == 0) {
        if (strstr(code, Bank1)) {
        	sprintf(fixcode, "%s%.3s%.13s%s%.8s", VNcode, tenNH, inaccount, inname, date);
        	fixcode[strlen(fixcode)] = '\0';
        	printf("%s", fixcode);
        }
        else if (strstr(code, Bank2)) {
        	sprintf(fixcode, "%s%.8s%.3s%.15s%s", VNcode, date, tenNH, inaccount, inname);
        	fixcode[strlen(fixcode)] = '\0';
        	printf("%s", fixcode);
        }
        else if (strstr(code, Bank3)) {
        	sprintf(fixcode, "%s%s%.8s%.6s%.3s", VNcode, inname, inaccount, date, tenNH);
        	fixcode[strlen(fixcode)] = '\0';
        	printf("%s", fixcode);
        }
    }
    if (ecode == 1) {
    	if (strstr(code, Bank1)) {
        	sprintf(fixcode, "%s%.3s%.13s%s%.8s", VNcode, tenNH, inaccount, inname, date);
        	fixcode[strlen(fixcode)] = '\0';
        }
        else if (strstr(code, Bank2)) {
        	sprintf(fixcode, "%s%.8s%.3s%.15s%s", VNcode, date, tenNH, inaccount, inname);
        	fixcode[strlen(fixcode)] = '\0';
        }
        else if (strstr(code, Bank3)) {
        	sprintf(fixcode, "%s%s%.8s%.6s%.3s", VNcode, inname, inaccount, date, tenNH);
        	fixcode[strlen(fixcode)] = '\0';
        }
        char table1[100];
    	char table2[100];
    	char table[200];
    	int i;
		int a = 0;
		int j = 0;
    	for (i = 65; i <= 90; i++) {
        	table1[j++] = i;
        	table1[j++] = i + 32;
    	}
    	for (i = 48; i <= 57; i++) {
        	table2[a] = i;
        	a++;
    	}
    	sprintf(table, "%.52s%.10s", table1, table2);
    	table[strlen(table)] = '\0';
    	int len1 = strlen(fixcode);
    	int len2 = strlen(table);
    	int len3 = strlen(inname);
    	int d;
		d = (11 * len3) % len2;
    	int x, y;
    	for (m = 0; m < len1; m++) {
    		for (n = 0; n < len2; n++) {
    			if (fixcode[m] == table[n]) {
    				if (n >= len2 - d) {
    					x = (n + d) % len2;
    					printf("%c", table[x]);
    				}
    				else {
    					y = (n + d);
    					printf("%c", table[y]);
    				}
    			}
    		}
    	}		
	}	
}
int main(){
    int menu_code;
    scanf("%d", &menu_code);
    if(menu_code == 1)
        checkInfoQR();
    if(menu_code == 2)
        convertcode();
    if(menu_code == 3)
        encryptQR();
    return 0;
}
