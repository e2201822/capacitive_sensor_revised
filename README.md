# capacitive_sensor_revised

這個檔案是arduino的原始碼[capacitive_sensor_revised.ino](https://github.com/e2201822/capacitive_sensor_revised/blob/master/capacitive_sensor_revised.ino)
示範電路怎麼接[接線圖_一組.jpg](https://github.com/e2201822/capacitive_sensor_revised/blob/master/%E6%8E%A5%E7%B7%9A%E5%9C%96_%E4%B8%80%E7%B5%84.jpg)
先看一組的版本比較清楚 依此類推
多組的版本如下[接線圖_多組.jpg](https://github.com/e2201822/capacitive_sensor_revised/blob/master/%E6%8E%A5%E7%B7%9A%E5%9C%96_%E5%A4%9A%E7%B5%84.jpg)


teesy開發板的電路有內建觸控功能，只要一個pin接線到電容就好，並且內建touchRead()函式
arduino沒有內建，需要使用兩個pin來控制，需要載入額外的CapacitiveSensor.h函式庫
以下是下載位置
<https://github.com/arduino-libraries/CapacitiveSensor/zipball/master>
下載後解壓縮到arduino的安裝資料夾中的libraries資料夾 
舉例C:\Program Files (x86)\Arduino\libraries\
如果arduino IDE的<CapacitiveSensor.h>有變成紅色的關鍵字就代表載入成功

先宣告六組接收端，視情況刪減，多出來的接收端必須刪減程式碼，不能空接，不刪減程式碼的話，會造成執行緩慢，因為arduino一直檢查接收端是否timeout
如果有空接輸出端在JSON中會顯示"-2"
