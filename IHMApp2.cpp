#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <windows.h>

void mouseClick(int button) {
    INPUT input;
    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = (button == 0) ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = (button == 0) ? MOUSEEVENTF_LEFTUP : MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Erreur : la caméra ne peut pas être ouverte." << std::endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty()) {
            std::cerr << "Erreur : la capture d'image a échoué." << std::endl;
            break;
        }

        cv::Mat redMask, blueMask, greenMask;
        cv::inRange(frame, cv::Scalar(0, 0, 150), cv::Scalar(100, 100, 255), redMask); // Rouge
        cv::inRange(frame, cv::Scalar(150, 0, 0), cv::Scalar(255, 100, 100), blueMask); // Bleu
        cv::inRange(frame, cv::Scalar(0, 150, 0), cv::Scalar(100, 255, 100), greenMask); // Vert

        cv::Moments mRed = cv::moments(redMask);
        cv::Moments mBlue = cv::moments(blueMask);
        cv::Moments mGreen = cv::moments(greenMask);

        if (mRed.m00 > 0) {
            int x = static_cast<int>(mRed.m10 / mRed.m00);
            int y = static_cast<int>(mRed.m01 / mRed.m00);

            // Déplacer le curseur de la souris à la position (x, y)
            SetCursorPos(x, y);
        }
       
        // Si un objet bleu est détecté, simuler un clic droit de la souris
        if (mBlue.m00 > 0) {
            mouseClick(1);
        }

        // Si un objet vert est détecté, simuler un clic gauche de la souris
        if (mGreen.m00 > 0) {
            mouseClick(0);
        }

        // Afficher l'image avec la détection de couleur
        cv::imshow("Color Detection", frame);

        // Touche pour quitter (appuyez sur 'q')
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}