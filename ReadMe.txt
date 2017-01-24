
use
make -f makefile3.txt 


===========================
在默认的情况下，产生这个错误的程序也会被中止。但是，这（以及是否产生错误信息）可以通过环境变量 MALLOC_CHECK_ 来控制。以下的设置是被支持的： 
 
0 - 不产生错误信息，也不中止这个程序 
 
1 - 产生错误信息，但是不中止这个程序 
 
2 - 不产生错误信息，但是中止这个程序 
 
3 - 产生错误信息，并中止这个程序 


===========================
route delete 0.0.0.0
route add 0.0.0.0 mask 0.0.0.0 192.168.0.254 metric 1

route delete 0.0.0.0
route add 0.0.0.0 mask 0.0.0.0 192.168.1.1 metric 1

route delete 0.0.0.0
route add 0.0.0.0 mask 0.0.0.0 192.168.31.1 metric 1
route print


robocopy a1 a2222 /mir /r:2 /w:3 /mon:2 /mot:2



