#include<opencv2/opencv.hpp>//library openCV
#include<iostream>

using namespace std;
using namespace cv;

void tersimpan(VideoWriter simpan_video, VideoCapture kamera){//prosedur video tersimpan
    string nama_jendela="Rekaman";//variabel untuk nama window pada window frame
    namedWindow(nama_jendela);//memanggil nama variabel nama_jendela
    while (true)//keadaan jika benar
    {
        Mat frame;//membuat variabel frame dengan tipe data Matriks(array)
        bool sukses=kamera.read(frame);//inisialisasi variabel sukses(boolean) dari kamera
        if(sukses==false){//jika gagal
            cout<<"Tidak dapat menyimpan\n";
            cin.get();
            break;
        }
        simpan_video.write(frame);//menyimpan video dari tangkapan kamera(frame)
        imshow(nama_jendela, frame);//menampilkan rekaman/hasil merekam(frame)
        if(waitKey(1)==27){//perintah keyboard
            cout<<"Telah berhenti merekam\n";
            break;
        }
        /* code */
    }
    
}
void merekam(VideoCapture kamera){//prosedur merekam video
    int lebar_frame=static_cast<int>(kamera.get(CAP_PROP_FRAME_WIDTH));//membuat variabel lebar_frame
    int tinggi_frame=static_cast<int>(kamera.get(CAP_PROP_FRAME_HEIGHT));//membuat variabel tinggi_frame

    Size ukuran_frame(lebar_frame, tinggi_frame);//ukuran lebar x tinggi frame video
    int fps=24;//jumlah frame/detik
    VideoWriter simpan_video("hasil_rekaman_v2.mp4", VideoWriter::fourcc('M', 'P', 'E', 'G'), fps, ukuran_frame, true);
    /*membuat variabel simpan_video untuk menyimpan video
      dengan codec video MPEG
    */
    if(simpan_video.isOpened()==true){//keadaan berhasil membuka fungsi simpan_video
        tersimpan(simpan_video, kamera);//memanggil prosedur tersimpan
    }
}
int main(){//program utama
    VideoCapture kamera(0);//variabel kamera 0(device utama)
    if(kamera.isOpened()==true){
        merekam(kamera);//memanggil prosedur merekam dengan parameter kamera
    }
    else{
        cout<<"Tidak dapat mengakses kamera\n";
        cin.get();
        return -1;
    }
    return 0;
}
