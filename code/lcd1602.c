#include<string>
#include<common.h>

sbit rs=P3^2;
sbit rw=P3^3;
sbit en=P3^6;



/*�����*/
void lcd_cmd(uchar x)
{
  rs=0;
  rw=0;
  P1=x;
  //delay(5);
  en=1;
  delay(5);
  en=0;
}

/*���ݺ���*/
void lcd_data(uchar y)
{
  rs=1;
  rw=0;
  P1=y;
  //delay(5);
  en=1;
  delay(5);
  en=0;
}

/*��ʼ��*/
void lcd_init()
{
  lcd_cmd(0x38);//1602��ʾ��8���ݿ�
  lcd_cmd(0x0e);
  
  lcd_cmd(0x01);//����
  lcd_cmd(0x06);
  lcd_cmd(0x02);
}

/**/
void main()
{
  char a[]="date:2017.04.04";
  char *p;
  p=a;
  lcd_init();
  lcd_cmd(0x80);
  while(*p!='\0')
  lcd_data(*p++);
  
}

