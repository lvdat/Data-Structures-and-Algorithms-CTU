
# Bài toán mã hoá chuỗi
Giả sử kiểu dữ liệu hàng đợi **Queue** đã được khai báo. Các phép toán cơ bản trên hàng đợi được hỗ trợ trong file thư viện **PQueue.c**
```c
void makenullQueue(Queue *pQ);
int emptyQueue(Queue Q);
ElementType front(Queue Q);
void deQueue(Queue *pQ);
void enQueue(ElementType x, Queue *pQ);  //ElementType là kiểu ký tự
```
Bằng cách sử dụng kiểu dữ liệu trừu tượng **Queue** đã cho, hãy viết chương trình mã hóa một thông điệp bằng khóa lặp lại.

# Dữ liệu đầu vào: 

Dòng 1: chuỗi cần mã hóa. Ví dụ chuỗi ```Hoc CTDL rat vui!```. 

Dòng 2: Khóa lặp lại: là một chuỗi các ký tự số ('1' - '9') mà chúng xác định mỗi ký tự được dịch chuyển về sau bao nhiêu vị trí. 

**Ví dụ:** nếu chuỗi cần mã hóa là "Hoc CTDL rat vui!" và khóa lặp là chuỗi "29137" thì:
- Ký tự đầu tiên của chuỗi cần mã hóa ('H') sẽ dịch chuyển về sau 2 vị trí => ký tự 'J'
- Ký tự kế tiếp của chuỗi cần mã hóa ('o') sẽ dịch chuyển về sau 9 vị trí => ký tự 'x' 
- Ký tự kế tiếp nữa của chuỗi cần mã hóa ('c') sẽ dịch chuyển về sau 1 vị trí => ký tự 'd'
- Ký tự ' ' sẽ dịch chuyển về sau 3 vị trí => ký tự '#'
- Ký tự 'C' sẽ dịch chuyển về sau 7 vị trí => ký tự 'J'
- Lúc này khóa "29137" đã hết, lại bắt đầu lặp lại khóa này.
- Ký tự 'T' sẽ dịch chuyển về sau 2 vị trí => ký tự 'V'
- Ký tự 'D' sẽ dịch chuyển về sau 9 vị trí => ký tự 'M'
- Và cứ tiếp tục như vậy.      
# Dữ liệu đầu ra
Dòng ghi chuỗi được mã hóa (xem thêm trong test case).

# Gợi ý:

- Sử dụng hàng đợi để lưu từng chữ số của khóa lặp. Khi chữ số ở đầu hàng đợi được sử dụng (để dịch chuyển ký tự trong chuỗi cần mã hóa) thì nó lại được đưa trở lại hàng đợi. 
- Duyệt từng ký tự trong chuỗi cần mã hóa và kết hợp với hàng đợi để mã hóa (dịch chuyển) ký tự này.

_(Dữ liệu đầu vào luôn hợp lệ, sinh viên không cần kiểm tra)_

# Sample Testcase
- Input 1:
```
Hoc CTDL rat vui!
29137
```
- Output 1:
```
Jxd#JVMM#yc}!y|k*
```
- Input 2:
```
Hang doi duoc su dung de luu khoa lap trong bai toan ma hoa.
6842
```
- Output 2:
```
Niri&lsk&lyqi(ww&lypm(hg&tyw&slqg(pcv(xtuvk"him"zwep&ue"nwe0
```

# Solution
Xem lời giải tại [encrypt.c](encrypt.c)