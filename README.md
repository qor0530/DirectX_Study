# DirectX_Study
directX2D프로그래밍

1. 속성에서 라이브러리 설정
2. 핸들 전역변수로 설정 후 메세지 출력방식 변경
3. GameSystem , GraphicManager 생성 (GraphicManager 는 항상 static 으로 선언하고 Update->Load_Bitmap)
4. step2 먼저 가서 복붙
5. cocreateinstance 찾아서 복붙
6. how to bitmap load 파일에서 정의 복붙
7. GameObject 생성후 헤더에서 ID2D1Bitmap으로 pBitmap 생성
8. GameSystem 가서 GameObject로 obj 만들고 new, Load_Bitmap, delete 설정
9. 그래픽 render 에 CreateBitmapBrush 사용후 fillRectangle 사용 
10. BeginDraw, EndDraw (BeginDraw엔 Clear포함)
11. 메세지 루프 가서 그래픽 Init후 GameSystem 선언 후 render, update설정
