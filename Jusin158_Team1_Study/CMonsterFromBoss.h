#include "CMonster.h"

class CMonsterFromBoss : public CMonster
{
private:
public:
	CMonsterFromBoss();
	virtual ~CMonsterFromBoss();

public:
	void	Initialize()						override;
	int		Update()							override;
	void	LateUpdate()						override;
	void	Render(HDC _hDC)					override;
	void	Release()							override;
	void	OnCollision(CObject* _pColObj, Vector2 _vColSize)		override;
};