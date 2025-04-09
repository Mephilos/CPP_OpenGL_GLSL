VC_MyOpenGL_BasicMyCode / 4. 8. 25

OpenGL로 FPS 게임 엔진 기틀 만들기

전체적인 구조 틀 계획


해더
----
Camera // 카메라 컨트롤
ShaderManager //셰이더 파일 관리 통합,
shader
Renderer // 렌더러  
objMesh//오브젝트 정점 관리
objectLayout//오브젝트 위치
TextureLoader 텍스처 로더 : 텍스처 추가시 편의성
SceneInitailizer 시작시 창 초기화
Input // 플레이어 컨트롤
GameManager // 스코어, 게임씬, 전반적인 게임 런타임 관리

세이더
----


리소스
----



----
main.cpp


추후 세분화 예정 GameScenes, GameController, Score 등



