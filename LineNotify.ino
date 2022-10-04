
#include <TridentTD_LineNotify.h>

#define SSID        "---------------------------"  // ชื่อไวไฟ
#define PASSWORD    "---------------------------"  // รหัสไวไฟ
#define LINE_TOKEN  "---------------------------"  // token line

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);

  // ตัวอย่างส่งข้อความ
  LINE.notify("สวัสดีชาวโลก");

  // ตัวอย่างส่งข้อมูล ตัวเลข
  LINE.notify(1234);          // จำนวนเต็ม
  LINE.notify(212.43434,5);   // จำนวนจริง แสดง 5 หลัก

  // เลือก Line Sticker ได้จาก https://devdocs.line.me/files/sticker_list.pdf
  LINE.notifySticker(3,240);        // ส่ง Line Sticker ด้วย PackageID 3 , StickerID 240
  LINE.notifySticker("Hello",1,2);  // ส่ง Line Sticker ด้วย PackageID 1 , StickerID 2  พร้อมข้อความ

  // ตัวอย่างส่ง รูปภาพ ด้วย url
  LINE.notifyPicture("https://www.ai-corporation.net/wp-content/uploads/2021/10/the-innovation-3.png"); // ส่งรูป
  LINE.notifyPicture("โลโก้เว็บไซต์","https://www.ai-corporation.net/wp-content/uploads/2021/10/the-innovation-3.png"); // ส่งข้อความ พร้อมรูปภาพ
}

void loop() {
  delay(1);
}
