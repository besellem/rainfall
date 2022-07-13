#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

char	*auth;
char	*service;


int		main(void)
{
	do
	{
		printf("%p, %p \n", auth, service);
		var_A8 = &var_88;

		if (fgets(var_A8, 128, stdin) == 0)
			break;

		if (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)) == 0)
		{
			auth = malloc(4);
			*auth = 0;
			ecx = 0xffffffff;
			asm
			{ repne scasb al, byte [edi] };
			if (!ecx <= 31)
			{
				strcpy(auth, &var_88 + 5);
			}
		}

		if (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)) == 0)
			free(auth);
		
		if (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)) == 0)
			service = strdup(&var_88 + 7);
		
		if (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)) != 0)
			continue;

		if (auth[32] != 0)
			system("/bin/sh");
		else
			fwrite("Password:\n", 1, 10, stdout);
	} while (true);

	return 0;
}




// int		main(void)
// {
// 	char			cVar1;
// 	char			*buf_ptr;
// 	int				iVar3;
// 	unsigned int	u_val;
// 	char			*pbVar5;
// 	char			*pbVar6;
// 	bool			bVar7;
// 	bool			uVar8;
// 	bool			uVar9;
// 	bool			buf_check;
// 	bool			uVar11;
// 	char			unused_c;
// 	char			buf[5];
// 	char			local_8b[2];
// 	char			acStack137[125];

// 	unused_c = 0;
// 	do
// 	{
// 		printf("%p, %p \n", auth, service);
// 		buf_ptr = fgets((char *)buf, 128, stdin);
// 		bVar7 = false;
// 		buf_check = buf_ptr == NULL;

// 		if (buf_check)
// 			return 0;

// 		iVar3 = 5;
// 		pbVar5 = buf;
// 		pbVar6 = (char *)"auth ";
// 		do
// 		{
// 			if (iVar3 == 0)
// 				break;
// 			iVar3 = iVar3 + -1;
// 			bVar7 = *pbVar5 < *pbVar6;
// 			buf_check = *pbVar5 == *pbVar6;
// 			pbVar5 = pbVar5 + (unsigned int)unused_c * -2 + 1;
// 			pbVar6 = pbVar6 + (unsigned int)unused_c * -2 + 1;
// 		} while (buf_check);

// 		uVar8 = 0;
// 		uVar11 = (!bVar7 && !buf_check) == bVar7;
		
// 		if ((bool)uVar11)
// 		{
// 			auth = (char *)malloc(4);
// 			*auth = 0;
// 			u_val = 0xffffffff;
// 			buf_ptr = local_8b;
// 			do
// 			{
// 				if (u_val == 0)
// 					break;
// 				u_val = u_val - 1;
// 				cVar1 = *buf_ptr;
// 				buf_ptr = buf_ptr + (unsigned int)unused_c * -2 + 1;
// 			} while (cVar1 != '\0');
			
// 			u_val = ~u_val - 1;
// 			uVar8 = u_val < 0x1e;
// 			uVar11 = u_val == 0x1e;

// 			if (u_val < 0x1f)
// 			{
// 				strcpy((char *)auth, local_8b);
// 			}
// 		}
		
// 		iVar3 = 5;
// 		pbVar5 = buf;
// 		pbVar6 = (char *)"reset";
// 		do
// 		{
// 			if (iVar3 == 0)
// 				break;
// 			iVar3 = iVar3 + -1;
// 			uVar8 = *pbVar5 < *pbVar6;
// 			uVar11 = *pbVar5 == *pbVar6;
// 			pbVar5 = pbVar5 + (unsigned int)unused_c * -2 + 1;
// 			pbVar6 = pbVar6 + (unsigned int)unused_c * -2 + 1;
// 		} while ((bool)uVar11);
		
// 		uVar9 = 0;
// 		uVar8 = (!(bool)uVar8 && !(bool)uVar11) == (bool)uVar8;
// 		if ((bool)uVar8)
// 		{
// 			free(auth);
// 		}
		
// 		iVar3 = 6;
// 		pbVar5 = buf;
// 		pbVar6 = (char *)"service";
// 		do
// 		{
// 			if (iVar3 == 0)
// 				break;
// 			iVar3 = iVar3 + -1;
// 			uVar9 = *pbVar5 < *pbVar6;
// 			uVar8 = *pbVar5 == *pbVar6;
// 			pbVar5 = pbVar5 + (unsigned int)unused_c * -2 + 1;
// 			pbVar6 = pbVar6 + (unsigned int)unused_c * -2 + 1;
// 		} while ((bool)uVar8);

// 		uVar11 = 0;
// 		uVar8 = (!(bool)uVar9 && !(bool)uVar8) == (bool)uVar9;
// 		if ((bool)uVar8)
// 		{
// 			uVar11 = (char *)0xfffffff8 < buf;
// 			uVar8 = acStack137 == NULL;
// 			service = strdup(acStack137);
// 		}

// 		iVar3 = 5;
// 		pbVar5 = buf;
// 		pbVar6 = (char *)"login";
// 		do
// 		{
// 			if (iVar3 == 0)
// 				break;
// 			iVar3 = iVar3 + -1;
// 			uVar11 = *pbVar5 < *pbVar6;
// 			uVar8 = *pbVar5 == *pbVar6;
// 			pbVar5 = pbVar5 + (unsigned int)unused_c * -2 + 1;
// 			pbVar6 = pbVar6 + (unsigned int)unused_c * -2 + 1;
// 		} while ((bool)uVar8);

// 		if ((!(bool)uVar11 && !(bool)uVar8) == (bool)uVar11)
// 		{
// 			if (auth[8] == 0)
// 			{
// 				fwrite("Password:\n", 1, 10, stdout);
// 			}
// 			else
// 			{
// 				system("/bin/sh");
// 			}
// 		}
// 	} while(true);
// }
