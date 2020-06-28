#include <CapacitiveSensor.h> // 載入CapacitiveSensor函式庫
// teesy開發板的電路有內建觸控功能，只要一個pin接線到電容就好，並且內建touchRead()函式
// arduino沒有內建，需要使用兩個pin來控制，需要載入額外的CapacitiveSensor.h函式庫
// 以下是下載位置
// https://github.com/arduino-libraries/CapacitiveSensor/zipball/master
// 下載後解壓縮到arduino的安裝資料夾中的libraries資料夾 
// 舉例C:\Program Files (x86)\Arduino\libraries\
// 如果上面的<CapacitiveSensor.h>有變成紅色的關鍵字就代表載入成功

CapacitiveSensor cs_2_8 = CapacitiveSensor(2,8); // pin2 pin8之間放1M ohm的電阻，電容接收端連接到pin8
CapacitiveSensor cs_3_9 = CapacitiveSensor(3,9); // pin3 pin9之間放1M ohm的電阻，電容接收端連接到pin9
CapacitiveSensor cs_4_10 = CapacitiveSensor(4,10); // pin4 pin10之間放1M ohm的電阻，電容接收端連接到pin10
CapacitiveSensor cs_5_11 = CapacitiveSensor(5,11); // pin5 pin11之間放1M ohm的電阻，電容接收端連接到pin11
CapacitiveSensor cs_6_12 = CapacitiveSensor(6,12); // pin6 pin12之間放1M ohm的電阻，電容接收端連接到pin12
CapacitiveSensor cs_7_13 = CapacitiveSensor(7,13); // pin6 pin12之間放1M ohm的電阻，電容接收端連接到pin12
// 先宣告六組接收端，視情況刪減，多出來的接收端必須刪減程式碼，不能空接，不刪減程式碼的話，會造成執行緩慢，因為arduino一直檢查接收端是否timeout
// 如果有空接輸出端在JSON中會顯示"-2"

void setup() {
  cs_2_8.set_CS_AutocaL_Millis(0xFFFFFFFFF); // 關閉autoCalibrate功能
  cs_3_9.set_CS_AutocaL_Millis(0xFFFFFFFFF);
  cs_4_10.set_CS_AutocaL_Millis(0xFFFFFFFFF);
  cs_5_11.set_CS_AutocaL_Millis(0xFFFFFFFFF);
  cs_6_12.set_CS_AutocaL_Millis(0xFFFFFFFFF);
  cs_7_13.set_CS_AutocaL_Millis(0xFFFFFFFFF);
  
  Serial.begin(9600);
  
}


void loop() {
  // JSON is a way to structure data that is easy to work with in
  // Processing. 
  // 存成JSON這種資料格式方便和processing溝通
  String json;
  long sensor1 = 0;
  long sensor2 = 0;
  long sensor3 = 0;
  long sensor4 = 0;
  long sensor5 = 0;
  long sensor6 = 0;

  // I assigned a lowercase letter to each touch sensor. 
  // In our case, we had 6 sensors that I named a-f. We read
  // from each sensor and then assemble the JSON from concatenated 
  // strings. The JSON for this example looks like: 
  // {a:1000,b:1,c:1200,d:3000,e:4000,f:2000}
  
  
  json = "{\"a\":";
  sensor1 = cs_2_8.capacitiveSensor(50);
  json = json + sensor1;
  // 第一組輸入

  json = json + ",\"b\":";
  sensor2 = cs_3_9.capacitiveSensor(50);
  json = json + sensor2;
  // 第二組輸入
  
  json = json + ",\"c\":";
  sensor3 = cs_4_10.capacitiveSensor(50);
  json = json + sensor3;
  // 第三組輸入
  
  json = json + ",\"d\":";
  sensor4 = cs_5_11.capacitiveSensor(50);
  json = json + sensor4;
  // 第四組輸入
  
  json = json + ",\"e\":";
  sensor5 = cs_6_12.capacitiveSensor(50);
  json = json + sensor5;
  // 第五組輸入
  
  json = json + ",\"f\":";
  sensor6 = cs_7_13.capacitiveSensor(50);
  json = json + sensor6;
  // 第六組輸入
  
  json = json + "}";

  // This gets printed to Serial, which Processing will read.
  Serial.println(json);
  delay(10);
}
