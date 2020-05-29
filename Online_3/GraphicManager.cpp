#include "GraphicManager.h"

ID2D1Factory* GraphicManager::pD2DFactory = NULL; //step2
ID2D1HwndRenderTarget* GraphicManager::pRT = NULL; //step3
IWICBitmapDecoder* GraphicManager::pDecoder = NULL;
IWICBitmapFrameDecode* GraphicManager::pSource = NULL;
IWICStream* GraphicManager::pStream = NULL;
IWICFormatConverter* GraphicManager::pConverter = NULL;
IWICBitmapScaler* GraphicManager::pScaler = NULL; //how to load a bitmap 
IWICImagingFactory* GraphicManager::pIWICFactory = NULL; 
ID2D1BitmapBrush* GraphicManager::m_pBitmapBrush = NULL;

void GraphicManager::Init(HWND hwnd)
{
    D2D1CreateFactory(
        D2D1_FACTORY_TYPE_SINGLE_THREADED,
        &pD2DFactory
    );

    // Obtain the size of the drawing area.
    RECT rc;
    GetClientRect(hwnd, &rc);

    // Create a Direct2D render target			
        pD2DFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(
            hwnd,
            D2D1::SizeU(
                rc.right - rc.left,
                rc.bottom - rc.top)
        ),
        &pRT
    ); //step3
    CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pIWICFactory));
    IID_PPV_ARGS(&pIWICFactory);
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
        &obj->pBitmap
    );
   
}

void GraphicManager::Render(GameObject* obj)
{
     pRT->CreateBitmapBrush(
        obj->pBitmap,
        &m_pBitmapBrush
    );
     float width = obj->pBitmap->GetPixelSize().width;
     float height = obj->pBitmap->GetPixelSize().height;
    //pRT->SetTransform(D2D1::Matrix3x2F::Rotation(obj->angle,
    //    D2D1::Point2F(width/2, height/2)));
    pRT->SetTransform(D2D1::Matrix3x2F::Translation(obj->position.x,obj->position.y));
    pRT->FillRectangle(D2D1::RectF(0,0,width,height), m_pBitmapBrush);
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
