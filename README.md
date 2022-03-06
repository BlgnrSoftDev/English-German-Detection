# English-German-Detection
<br>
1.sınıfta grup ödevi olarak yaptığımız bu proje, verilen metinin inglizice mi yoksa almanca mı yazıldığındığını tespit eder.
<h2>Görev</h2>
Kullanıcıdan bir metin alınacaktır. Kullanıcıdan alınan metin üzerinde önceden belirlenmiş olan bigram ve trigramların frekansları hesaplanacaktır (frekans hesaplaması; her bir bigramın ve her bir trigramın bu metinde kaç kez geçtiğinin bulunması). Bu hesaplamalar sonucunda elde ettiğiniz frekans matrisi ile size taslak kod içerisinde verilen frekans matrisi (bu matriste İngilizce ve Almanca dillerinin frekans değerleri yer almaktadır) karşılaştırılacaktır. İngilizce ve Almanca dillerinin her birinin frekansları ile sizin elde ettiğiniz frekans matrisi arasında ayrı ayrı uzaklık hesabı yapılacaktır .Hangi dil ile daha küçük uzaklık değeri elde edildiyse, metnin yazıldığı dil olarak o dil tahmin edilecektir.

<h2>Karşılaştığımız sorunlar</h2>

•	Basit sözdizimi hataları.
<br>
•	Programın sonsuz döngüye girmesi.
<br>
•	Bigram ve trigram frekans matrislerini döngü içerisinde kullanırken döngü sonlandırıcı olarak NULL karakterini kullanmamız ve karakter matrislerinde döngüyü durdurabilecek bir NULL karakteri bulunmadığından döngüye eklediğimiz printf() fonksyonunun önce matrisi yazdırıp sonrasında hızını alamayıp bütün önbelleği ekrana yazdırması.
<br>
•	Karşılaştırma operatörü kullanırken yaşadığımız mantık hataları.
<br>
•	Öklit uzaklık hesabının yanlış yapılması.
<br>
•	Derleyici uyumsuzlukları. (İntel c++ derleyicisi ile GNU GCC derleyici)
<br>

<h2>Programlama Aşamaları</h2>

•	İlk önce ödev verildiği ilk gün grup arkadaşım Yusuf ile beraber 2-3 saatlik meeting düzenledik ve genel olarak projemizi çözümlemeye ve genel problemlerin meydana çıkarılması işlemleri yaptık,  proje taslağında tutarsızlıklar olduğunu keşfettik ve bunu geri bildirim olarak hocalarımıza e-mail aracılığıyla gönderdik.
<br>
•	Bu işlemlerimizden 2 gün sonra projede bulduğumuz tutarsızlıklar araştırma görevlisi hocalarımız tarafından giderildi ve projemize tam anlamıyla başladık. Öncelikle projelerin en önemli kısmı olan ‘Algoritma’ hakkında beyin fırtınası yaptık ve ortak kararımız ile  divide and conqure (böl ve fethet) yaklaşımıyla algoritmamızı hazırlamaya koyulduk. Proje taslağında genel olarak ihtiyacımız olan çoğu argüman verildiği için algoritma kurmamız bir o kadar da kolaylaştı. Kağıt kalem veya  flowchart (akış şeması) kullanmadan aklımızdan algoritmayı kurduk.
<br>
•	İlk yaklaşımımız genel olarak fonksiyonları yazmak oldu. Grup arkadaşımla olabildiğince eşit iş dağılımıyla fonksiyonları yazmaya koyulduk ilk fonksiyon olan filtreleme işlemi oldukça kolaydı ve onu hızlı bir şekilde yazdık ama bu kısımda problem sayılmaz ama kod çeşitliği açısından ternary operatör kullanımında az bir süre takıldık. Sonra projenin en önemli kısmı , ayrıca internet ve diğer kaynaklardan araştırmamız sonucu öğrendiğimiz NLP (doğal dil işleme) ‘nin temel konseptlerinden olan bigram ve trigram (N-grams) frekans hesaplanması işlemini yazmaya koyulduk. Bigram hesaplanması algoritmasını kurunca küçük değişiklikler ile aynı zamanda trigram hesaplanması algoritmasını kurmuş olduk. Grup arkadaşım Yusuf ile Derin bir düşünme ve tartışma sonucu fonksiyonları yazdık ve projemizin %80’i bitmiş oldu.
<br>
•	Son kullanıcın girdiği metnin içindeki bigram ve trigram hesaplanması işleminden sonraki aşamamız olan ‘uzaklık’ işlemine geçiş yaptık.Uzaklık işlemini hesaplamak için hocalarımızın bize verdiği taslakta sadece öneri verdiği ve özgür olduğumuz söylenmişti. Bizde araştırmalarımız sonucu etkili ve temel bir yöntem olan Euclidean (Öklid) uzaklığını kullanmaya karar verdik.
<br>
•	Ve son aşamamız olan girilen metnin tahmin edilmesi fonksiyonu ile ufak tefek internet bağlantısı sorunlarıyla projemizin kodlama kısmını bitirmiş oldu. Genel kodlama işleminin bitmesi ardından en heyecanlı kısım olan deneme kısımlarına geçtik ve bizi çok mutlu eden sonuçlarla algoritmamız %0 hata payıyla çaılştı. Tahmin kısmından iyice emin olduktan sonra kodumuzun estetiklik olarak eksiklik içerdiğini düşündük. Ve birkaç güzelleştirmeyle console ekranında daha estetik bir kullanıcı deneyimi elde ettik. Son aşamamız olan projemizi değerlendirecek hoca veya hocalarımızın nerede , ne yapmak istediğimizi açık ve sade bir şekilde anlatmak için yorum satırları ekledik ve ardından projemizi kutusuna koyduk.
<br>
•	Yazdığımız bu raporla birlikte günlük 2 – 3 saat düzenli ve verimli çalışma ile toplamda 14-16 saat vaktimizi ayırdığımız, tecrübesiz bilgisayar mühendisi öğrencileri olarak takım çalışmasının önemini ve gerekliliğini kavradık ve tecrübe edindik bize çok şey katan bu projeyi sunuma hazır bir hale getirdik.
