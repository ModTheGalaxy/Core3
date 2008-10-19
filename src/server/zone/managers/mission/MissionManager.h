/*
 *	server/zone/managers/mission/MissionManager.h generated by engine3 IDL compiler 0.55
 */

#ifndef MISSIONMANAGER_H_
#define MISSIONMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

class Player;

class MissionObject;

class TangibleObject;

class ZoneServer;

#include "server/zone/ZoneProcessServerImplementation.h"

class MissionManager : public DistributedObjectStub {
public:
	MissionManager(ZoneServer* zs, ZoneProcessServerImplementation* ps);

	void init();

	void unloadManager();

	void removeMissions();

	MissionObject* poolMission(string& dbKey, int termMask, const string& typeStr, unsigned int descKey, unsigned int titleKey, unsigned int diffLv, float destX, float destY, unsigned int destPlanetCrc, const string& creatorName, unsigned int rewardAmount, float targetX, float targetY, unsigned int targetPlanetCrc, unsigned int depictedObjCrc, const string& descriptionStf, const string& titleStf, unsigned int typeCrc, TangibleObject* deliverItem = NULL, bool doLock = true);

	void setupHardcodeMissions();

	void sendTerminalData(Player* player, int termBitmask, bool doLock = true);

	void sendMission(Player* player, string& tKey, bool doLock = true);

	void doMissionAccept(Player* player, unsigned long long oid, bool doLock = true);

	void doMissionComplete(Player* player, string& tKey);

	void doMissionAbort(Player* player, unsigned long long oid, bool doLock = true);

	void doMissionAbort(Player* player, string& tKey, bool doLock = true);

	void removeMisoFromPool(MissionObject* miso, bool doLock = true);

	unsigned int getMissionItemCrc(string& tKey, bool doLock = true);

	void loadMissionScripts();

	void registerFunctions();

	void registerGlobals();

protected:
	MissionManager(DummyConstructorParameter* param);

	virtual ~MissionManager();

	friend class MissionManagerHelper;
};

class MissionManagerImplementation;

class MissionManagerAdapter : public DistributedObjectAdapter {
public:
	MissionManagerAdapter(MissionManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void init();

	void unloadManager();

	void removeMissions();

	MissionObject* poolMission(string& dbKey, int termMask, const string& typeStr, unsigned int descKey, unsigned int titleKey, unsigned int diffLv, float destX, float destY, unsigned int destPlanetCrc, const string& creatorName, unsigned int rewardAmount, float targetX, float targetY, unsigned int targetPlanetCrc, unsigned int depictedObjCrc, const string& descriptionStf, const string& titleStf, unsigned int typeCrc, TangibleObject* deliverItem, bool doLock);

	void setupHardcodeMissions();

	void sendTerminalData(Player* player, int termBitmask, bool doLock);

	void sendMission(Player* player, string& tKey, bool doLock);

	void doMissionAccept(Player* player, unsigned long long oid, bool doLock);

	void doMissionComplete(Player* player, string& tKey);

	void doMissionAbort(Player* player, unsigned long long oid, bool doLock);

	void doMissionAbort(Player* player, string& tKey, bool doLock);

	void removeMisoFromPool(MissionObject* miso, bool doLock);

	unsigned int getMissionItemCrc(string& tKey, bool doLock);

	void loadMissionScripts();

	void registerFunctions();

	void registerGlobals();

protected:
	string _param0_poolMission__string_int_string_int_int_int_float_float_int_string_int_float_float_int_int_string_string_int_TangibleObject_bool_;
	string _param2_poolMission__string_int_string_int_int_int_float_float_int_string_int_float_float_int_int_string_string_int_TangibleObject_bool_;
	string _param9_poolMission__string_int_string_int_int_int_float_float_int_string_int_float_float_int_int_string_string_int_TangibleObject_bool_;
	string _param15_poolMission__string_int_string_int_int_int_float_float_int_string_int_float_float_int_int_string_string_int_TangibleObject_bool_;
	string _param16_poolMission__string_int_string_int_int_int_float_float_int_string_int_float_float_int_int_string_string_int_TangibleObject_bool_;
	string _param1_sendMission__Player_string_bool_;
	string _param1_doMissionComplete__Player_string_;
	string _param1_doMissionAbort__Player_string_bool_;
	string _param0_getMissionItemCrc__string_bool_;
};

class MissionManagerHelper : public DistributedObjectClassHelper, public Singleton<MissionManagerHelper> {
	static MissionManagerHelper* staticInitializer;

public:
	MissionManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<MissionManagerHelper>;
};

class MissionManagerServant : public DistributedObjectServant {
public:
	MissionManager* _this;

public:
	MissionManagerServant();
	virtual ~MissionManagerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*MISSIONMANAGER_H_*/
