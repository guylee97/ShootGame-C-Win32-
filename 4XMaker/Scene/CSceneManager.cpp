#include "CSceneManager.h"
#include "InGameScene.h"
#include "../Object/Player.h"
#include "Layer.h"


DEFINITION_SINGLE(CSceneManager)

CSceneManager::CSceneManager() :
	m_pScene(NULL),
	m_pNextScene(NULL)
{
}

CSceneManager::~CSceneManager()
{
	SAFE_DELETE(m_pScene);
}

bool CSceneManager::Init()
{
	CreateScene<CInGameScene>(SC_CURRENT);

	return true;
}

void CSceneManager::Input(float fDeltaTime)
{
	m_pScene->Input(fDeltaTime);
}

int CSceneManager::Update(float fDeltaTime)
{
	m_pScene->Update(fDeltaTime);
	return 0;
}

int CSceneManager::LateUpdate(float fDeltaTime)
{
	m_pScene->LateUpdate(fDeltaTime);
	return 0;
}

void CSceneManager::Collision(float fDeltaTime)
{
	m_pScene->Collision(fDeltaTime);
}

void CSceneManager::Render(HDC hdc, float fDeltaTime)
{
	m_pScene->Render(hdc,fDeltaTime);
}
