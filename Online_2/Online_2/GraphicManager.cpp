#include "GraphicManager.h"

ID2D1Factory* GraphicManager::pD2DFactory = NULL;
ID2D1HwndRenderTarget* GraphicManager::pRT = NULL;
IWICBitmapDecoder* GraphicManager::pDecoder = NULL;
IWICBitmapFrameDecode* GraphicManager::pSource = NULL;
IWICStream* GraphicManager::pStream = NULL;
IWICFormatConverter* GraphicManager::pConverter = NULL;
IWICBitmapScaler* GraphicManager::pScaler = NULL;
IWICImagingFactory* GraphicManager::pIWICFactory;
ID2D1BitmapBrush* GraphicManager::m_pBitmapBrush = NULL;
void GraphicManager::Init(HWND hWnd)
{
    D2D1CreateFactory(
        D2D1_FACTORY_TYPE_SINGLE_THREADED,
        &pD2DFactory
    );
    // Obtain the size of the drawing area. //step3
    RECT rc;
    GetClientRect(hWnd, &rc);

    // Create a Direct2D render target		

    pD2DFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(
            hWnd,
            D2D1::SizeU(
                rc.right - rc.left,
                rc.bottom - rc.top)
        ),
        &pRT
    );
    CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pIWICFactory));

}

void GraphicManager::Load_Bitmap(GameObject* obj, LPCWSTR name)
{
    pIWICFactory->CreateDecoderFromFilename(
        name,
        NULL,
        GENERIC_READ,
        WICDecodeMetadataCacheOnLoad,
        &pDecoder
    );

    pDecoder->GetFrame(0, &pSource);
    pIWICFactory->CreateFormatConverter(&pConverter);
    pConverter->Initialize(
        pSource,
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        NULL,
        0.f,
        WICBitmapPaletteTypeMedianCut
    );
    pRT->CreateBitmapFromWicBitmap(
        pConverter,
        NULL,
        &obj->pBitmap //���� ������ ��� �����͸� ����Ͽ� �ּҰ��� �ҷ����� &�ʿ�
    ); //bitmap�� �ҷ����� ���� // How to Load a Bitmap from a File���� �ο�



}

void GraphicManager::Render(GameObject* obj)
{
    pRT->CreateBitmapBrush(
        obj->pBitmap,
        &m_pBitmapBrush
    );
    pRT->FillRectangle(D2D1::RectF(0, 0, 100, 100), m_pBitmapBrush); //�귯�� ���� �� ��� - > ���簢�� ���
}

void GraphicManager::Release()
{
}

void GraphicManager::BeginDraw()
{
    pRT->BeginDraw();
    pRT->Clear();
}

void GraphicManager::EndDraw()
{
    pRT->EndDraw();
}
