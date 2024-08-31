## 16进制凯撒密码加密文件/ Hexadecimal Caesar
### 原理
将文件的16进制形式表示的每一位加1，例如1变换成2，A变换成B，F变换成0；同时还会给文件添加一个自定义的文件头部。我采用的是MinGW，当然也可以用Visual Studio。

<font color=red>注意：本套加密方法安全性低，敏感信息请使用更精巧的加密手段</font>


### 使用方法
#### 1.加密
把exe文件和待加密文件放在同一目录下，在目录位置下使用终端执行：

`decrypto.exe -e input.mp4 output.mp4`

其中，input.mp4和output.mp4为待加密和加密后的文件

#### 2.解密
把exe文件与待解密文件放在同一目录下，在目录位置下终端命令：

`decrypto.exe -d input.mp4 output.mp4`

其中，input.mp4和output.mp4为待解密和解密后的文件


### Principle
Add 1 to each hexadecimal bit of the file, for example, 1 becomes 2, A becomes B, and F becomes 0; a custom file header is also added to the file.  use MinGW, but you can also use Visual Studio.

<font color=red>Attention: This encryption method is not very secure. Please use more sophisticated encryption methods for sensitive information.</font>
### Usage
#### 1.Encryption
Put the exe file and the file to be encrypted in the same directory, and use the terminal to execute in the directory:

`decrypto.exe -e input.mp4 output.mp4`

Where input.mp4 and output.mp4 are the files to be encrypted and the encrypted files

#### 2.Decryption
Put the exe file and the file to be decrypted in the same directory, and run the terminal command in the directory:

`decrypto.exe -d input.mp4 output.mp4`

Where input.mp4 and output.mp4 are the files to be decrypted and the files after decryption.
