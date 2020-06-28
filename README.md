# capacitive_sensor_revised

這個檔案是arduino的原始碼capacitive_sensor_revised.ino
接線圖是示範電路怎麼接
先看一組的版本比較清楚 依此類推


teesy開發板的電路有內建觸控功能，只要一個pin接線到電容就好，並且內建touchRead()函式
arduino沒有內建，需要使用兩個pin來控制，需要載入額外的CapacitiveSensor.h函式庫
以下是下載位置
https://github.com/arduino-libraries/CapacitiveSensor/zipball/master
下載後解壓縮到arduino的安裝資料夾中的libraries資料夾 
舉例C:\Program Files (x86)\Arduino\libraries\
如果arduino IDE的<CapacitiveSensor.h>有變成紅色的關鍵字就代表載入成功

