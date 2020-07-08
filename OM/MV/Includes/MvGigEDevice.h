
#ifndef __MV_GIGE_DEVICE_H__
#define __MV_GIGE_DEVICE_H__

#include "MvDeviceBase.h"

namespace MvCamCtrl
{
    class CMvGigEDevice : public IMvDevice
    {
    public:

        // ���豸
        virtual int     Open(unsigned int nAccessMode = MV_ACCESS_Exclusive, unsigned short nSwitchoverKey = 0);


        // �ر��豸
        virtual int     Close();


        // �ж��豸��״̬����������falseʱ���ɴ��豸
        virtual bool    IsOpen();


        // ����ץͼ
        virtual int     StartGrabbing();


        // ֹͣץͼ
        virtual int     StopGrabbing();


        // ��ȡ�豸��Ϣ
        virtual int     GetDeviceInfo(MV_CC_DEVICE_INFO&);


        /** @fn     GetGenICamXML(unsigned char* pData, unsigned int nDataSize, unsigned int* pnDataLen)
         *  @brief  ��ȡ�豸��XML�ļ�
         *  @param  pData           [IN][OUT]   - ������Ļ����ַ
                    nDataSize       [IN]        - �����С
                    pnDataLen       [OUT]       - xml �ļ����ݳ���
         *  
         *  @return �ɹ�������MV_OK��ʧ�ܣ����ش�����
         *  @note   ��pDataΪNULL��nDataSize��ʵ�ʵ�xml�ļ�Сʱ�����������ݣ���pnDataLen����xml�ļ���С��
         *          ��pDataΪ��Ч�����ַ���һ����㹻��ʱ�������������ݣ�����pnDataLen����xml�ļ���С��
         */
        virtual int     GetGenICamXML(unsigned char* pData, unsigned int nDataSize, unsigned int* pnDataLen);


        /** @fn     GetOneFrame(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO* pFrameInfo)
         *  @brief  ��ȡһ֡ͼ������
         *  @param  pData           [IN][OUT]   - ����ָ��
                    nDataLen        [IN]        - ���ݳ���
                    pFrameInfo      [OUT]       - �����֡��Ϣ
         *  
         *  @return �ɹ�������MV_OK��ʧ�ܣ����ش�����
         */
        virtual int     GetOneFrame(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO* pFrameInfo);


        // ��ȡGenICamʹ�õĴ���������
        virtual TlProxy     GetTlProxy();


        virtual ~CMvGigEDevice( void );


        CMvGigEDevice( const MV_CC_DEVICE_INFO* pInfo );


        // ��ȡ������Ϣ
        virtual int     GetNetTransInfo(MV_NETTRANS_INFO* pstInfo);


        // ǿ��IP
        virtual int     ForceIp(unsigned int nIP);


        // ����IP��ʽ
        virtual int     SetIpConfig(unsigned int nType);


        // ��ȡ�������͵���Ϣ
        virtual int     GetAllMatchInfo(MV_ALL_MATCH_INFO* pstInfo);
        // add new interface here...

        // ע����Ϣ�쳣�ص�
        virtual int     RegisterExceptionCallBack(void(__stdcall* cbException)(unsigned int nMsgType, void* pUser),
                                                    void* pUser);

        virtual int     SetSingleShot(void(__stdcall* cbSingleShot)(unsigned char* pData , unsigned int nDataLen, 
                                                                    MV_FRAME_OUT_INFO* pFrameInfo, void* pUser), 
                                        void* pUser);

        // �����豸�ɼ�ģʽ
        virtual int     SetAcquisitionMode(MV_CAM_ACQUISITION_MODE enMode);


        // �豸��������
        virtual int     LocalUpgrade(const void *pFilePathName);

        // ��ȡ��ǰ��������
        virtual int     GetUpgradeProcess(unsigned int* pnProcess);

        virtual int     GetOptimalPacketSize();

        // ��ʾһ֡ͼ��
        virtual int     Display(void* hWnd);

        virtual int     SetNetTransMode(unsigned int nType);

        virtual int     ReadMemory(void *pBuffer, int64_t nAddress, int64_t nLength);

        virtual int     WriteMemory(const void *pBuffer, int64_t nAddress, int64_t nLength);

        // ����ֵ 0������������1������������
        virtual int     IsDriverWorking();

        // 0����������1������
        virtual int     SetThrowAbnormalImage(int bThrow);

        // ����SDK�ڲ�ͼ�񻺴�ڵ��������Χ[1, 30]����ץͼǰ����
        virtual int     SetImageNodeNum(unsigned int nNum);

        // ����gvcp��ʱʱ��
        virtual int     SetGvcpTimeout(unsigned int nTimeout);

        // ע��ͼ�����ݻص�
        virtual int     RegisterImageCallBack(void(__stdcall* cbOutput)(unsigned char * pData, MV_FRAME_OUT_INFO* pFrameInfo, void* pUser),
                                                    void* pUser);

        // ע��EVENT��Ϣ�ص�
        virtual int     RegisterEventCallBack(void(__stdcall* cbEvent)(unsigned int nUserDefinedId, void* pUser),
                                                void* pUser);

        // ע��ͼ�����ݻص�,chunk
        virtual int     RegisterImageCallBackEx(void(__stdcall* cbOutput)(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser),void* pUser);

		virtual int     RegisterImageCallBackForRGB(void(__stdcall* cbOutput)(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser),void* pUser);
		virtual int     RegisterImageCallBackForBGR(void(__stdcall* cbOutput)(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser),void* pUser);

        virtual int     GetOneFrameEx(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO_EX* pFrameInfo);

        virtual int     GetImageForRGB(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO_EX* pFrameInfo, int nMsec);
        virtual int     GetImageForBGR(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO_EX* pFrameInfo, int nMsec);

        virtual int     GetOneFrameTimeout(unsigned char * pData , IN unsigned int nDataSize, IN OUT MV_FRAME_OUT_INFO_EX* pFrameInfo, int nMsec);

    private:
        CDevRefs*       m_pRefs;
    };


}

#endif /* __MV_GIGE_DEVICE_H__ */