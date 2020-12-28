// 160crackme-001.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS        //去除安全函数的检查
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    //密码
    char key1[3] = "CW";
    char key2[8] = "CRACKED";
    //输入用户名
    char username[10] = { 0 };
    printf("请输入用户名 长度必须大于等于4:");
    scanf_s("%s", username, 10);
    //判断长度
    if (strlen(username) < 4)
    {
        printf("长度必须大于等于4,请重新输入\n");
    }
    //根据用户名生成密码
    //计算用户名的第一位
    int username1 = username[0];
    int result1 = (username1 << 0x3) - username1;  //左移0x3位再减去原来的值
    //计算用户名第二位
    int username2 = username[1];
    result1 = (username1 << 0x4) + result1;        //左移4位再加上原来的结果
    //计算用户名的第四位
    int username4 = username[3];
    int result2 = username4 * 0xB;                //乘以0xB
    //计算用户名的第三位
    int username3 = username[2];
    result2 = (username3 * 0xE) + result2;        //乘以0xE在加上第四位的结果
    //再次计算第一位
    int result3 = username1 * 0x29 * 2;            //如果u1参数此时字符0，则对应ASCII码是48或30H，
                                                   //是乘以0x29再乘以2，0x29是十进制的41，48*41=1968即7B0H,
    //将result3转为ASCII 并拼接密钥
    char key[50] = { 0 };
    sprintf(key, "%s-%d-%s", key1, result3, key2);
    //打印key
    printf("密钥为:%s\n", key);
    system("pause");
    return 0;
}