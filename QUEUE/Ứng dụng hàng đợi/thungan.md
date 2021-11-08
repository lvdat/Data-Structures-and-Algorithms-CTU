# Ứng dụng Queue: bài toán tính quầy thu ngân

Giả sử kiểu dữ liệu hàng đợi **Queue** đã được khai báo. Các phép toán cơ bản trên hàng đợi được hỗ trợ trong file thư viện **PIQueue.c**

```c
void makenullQueue(Queue *pQ);
int emptyQueue(Queue Q);
ElementType front(Queue Q);
void deQueue(Queue *pQ);
void enQueue(ElementType x, Queue *pQ);  //ElementType là kiểu số nguyên
```
Bằng cách sử dụng kiểu dữ liệu trừu tượng **Queue** đã cho, hãy viết chương trình tính số quầy thu ngân cần phải mở tại siêu thị Coopmart Cần Thơ vào một thời điểm cụ thể.

# Dữ liệu đầu vào:

- Dòng 1: Số khách hàng. 
- Dòng 2: Số quầy thu ngân tối đa có trong siêu thị.
- Dòng 3: Thời gian xử lý trung bình (số giây) cho 1 giao dịch tại quầy thu ngân. Ví dụ: thời gian từ lúc bắt đầu tới lượt khách được xử lý đơn hàng tại quầy thu ngân cho đến khi khách thanh toán xong và rời khỏi quầy là 120 giây.   
- Dòng 4: Thời gian trung bình (số giây) mà khách hàng sẽ đến xếp hàng thanh toán. Ví dụ: trung bình 15 giây thì có 1 khách hàng đến xếp hàng thanh toán.
Thời gian trung bình mà khách hàng phải bỏ ra từ lúc bắt đầu xếp hàng đến lúc thanh toán xong X giây. Ví dụ: khách hàng chỉ phải bỏ ra dưới 120 giây.

# Dữ liệu đầu ra (xem thêm trong test case):

Số quầy thu ngân mở và thời gian trung bình mà khách hàng phải bỏ ra.
Kết luận: số quầy thu ngân cần phải mở để khách hàng chỉ phải bỏ ra dưới X giây từ lúc bắt đầu xếp hàng đến lúc thanh toán xong.

# Gợi ý:
Thực hiện mô phỏng theo số lượng quầy thu ngân tăng dần (từ 1 đến số quầy thu ngân tối đa ) cho đến khi thời gian trung bình mà khách phải bỏ ra <=X thì dừng quá trình lặp và đưa ra kết luận. 

Với từng số lượng quầy: 

- Khởi tạo thời gian tại từng quầy bằng 0; 
- Đưa dữ liệu của khách hàng (thời gian đến của khách hàng) vào hàng đợi;
- Tính tổng thời gian mà tất cả các khách hàng trong hàng đợi phải bỏ ra từ lúc bắt đầu xếp hàng đến lúc thanh toán xong: 
  - Khởi đầu, tổng thời gian bằng 0; 
  - Trong khi hàng đợi chưa hết: Với lần lượt từng quầy thu ngân, nếu vẫn còn khách trong hàng đợi thì lấy thời gian đến của khách,  tính thời gian đi của khách (liên quan đến thời gian đến, thời gian tại quầy và thời gian xử lý trung bình cho 1 giao dịch), xóa khách khỏi hàng đợi, cập nhật lại thời gian tại quầy, cập nhật lại tổng thời gian. 
- Tính thời gian trung bình mà khách hàng phải bỏ ra dựa trên tổng thời gian và số lượng khách; so sánh với X để dừng quá trình lặp và đưa ra kết luận hay lại tiếp tục lặp.

![img](https://i.imgur.com/502Wp5S.png)

![image](https://user-images.githubusercontent.com/72507371/140720861-ed6844fa-0b8c-486e-9238-16f61426cd8f.png)

_(Dữ liệu đầu vào luôn hợp lệ, sinh viên không cần kiểm tra)_

# Sample Testcases:
Input 1
```
100
10
120
15
120
```
Output 1
```
So quay: 1; Thoi gian cho trung binh: 5317.0
So quay: 2; Thoi gian cho trung binh: 2325.0
So quay: 3; Thoi gian cho trung binh: 1332.0
So quay: 4; Thoi gian cho trung binh: 840.0
So quay: 5; Thoi gian cho trung binh: 547.0
So quay: 6; Thoi gian cho trung binh: 355.0
So quay: 7; Thoi gian cho trung binh: 219.0
So quay: 8; Thoi gian cho trung binh: 120.0
=> Sieu thi se mo 8 quay
```

Input 2:
```
150
5
150
30
60
```
Output 2:
```
So quay: 1; Thoi gian cho trung binh: 9090.0
So quay: 2; Thoi gian cho trung binh: 3480.0
So quay: 3; Thoi gian cho trung binh: 1620.0
So quay: 4; Thoi gian cho trung binh: 697.0
So quay: 5; Thoi gian cho trung binh: 150.0
Voi 5 quay hien co, khach phai cho it nhat 150.0 giay moi duoc phuc vu.
```
# Solution
Xem lời giải tại đây: [thungan.c](thungan.c)