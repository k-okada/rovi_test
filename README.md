# rovi_test

## directory 01/ 可変サイズtopicでのメモリーリーク(Python)  
std::vectorを含むtopic(ここではstd_msgs/Float32MultiArray)にて、メモリーリークが発生します。Pythonのみの現象。  
### 再現方法  
1. サブスクライバーを起動します
~~~
01/sub.py
~~~

2. パブリッシャをtopic長固定で起動します
~~~
rosrun rovi_test pubarray 500000
~~~

500000はstd::vectorのサイズです。1秒周期でpublishされるtopicをサブスクライバーが受信しても、この状態ではリークはありません。

3. パブリッシャをtopic長可変で起動します
~~~
rosrun rovi_test pubarray 500000 600000
~~~  
上記にてサイズが500000〜600000でランダムに可変になります。この状態ではリークが発生します。
