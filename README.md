# TCP/IP 网络编程

### 一.计算器服务器端/客户端

+   客户端连接到服务器端后以1字节整数形式传递待算数字个数。
+   客户端向服务器端传递的每个整数型数据占用4字节。
+   传递整数型数据后接着传递运算符，运算符信息占1字节。
+   选择字符 +、-、* 之一传递。
+   服务器端以4字节整数型向客户端传回运算结果。
+   客户端得到运算结果后终止与服务器端的连接。





