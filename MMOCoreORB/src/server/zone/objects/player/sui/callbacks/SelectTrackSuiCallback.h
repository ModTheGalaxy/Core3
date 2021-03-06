/*
 * DroidPlaybackSuiCallback.h
 *
 */

#ifndef DROIDPLAYBACKSUICALLBACK_H
#define DROIDPLAYBACKSUICALLBACK_H

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidPlaybackModuleDataComponent.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/sui/callbacks/DeleteTrackConfirmationSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

class SelectTrackSuiCallback : public SuiCallback {
public:
	SelectTrackSuiCallback(ZoneServer* server)
		: SuiCallback(server) {
	}

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
		bool cancelPressed = (eventIndex == 1);

		if (!suiBox->isListBox())
			return;

		if (args->size() < 2)
			return;

		bool otherPressed = Bool::valueOf(args->get(0).toString());
		int index = Integer::valueOf(args->get(1).toString());
		SuiListBox* listBox = cast<SuiListBox*>( suiBox);
		ManagedReference<SceneObject*> object = suiBox->getUsingObject().get();

		if (object == nullptr)
			return;

		DroidObject* droid = cast<DroidObject*>(object.get());

		if (droid == nullptr)
			return;

		Locker crosslock(droid,player);

		auto module = droid->getModule("playback_module").castTo<DroidPlaybackModuleDataComponent*>();

		if (module == nullptr)
			return;


		if (cancelPressed)
			return;

		if (index < 0 || index >= module->getTotalTracks())
			return;

		int trackPerformanceIndex = module->getTrackPerformanceIndex(index);

		if (otherPressed) { // Delete
			if (trackPerformanceIndex == 0) {
				player->sendSystemMessage("@pet/droid_modules:playback_msg_del_track_already_empty"); // You cannot erase a track that is already empty.
				return;
			}

			int trackPerformanceIndex = module->getTrackPerformanceIndex(index);
			String prompt = "@pet/droid_modules:playback_delete_title \n\n" + module->getTrackName(trackPerformanceIndex);

			ManagedReference<SuiMessageBox*> box = new SuiMessageBox(player, SuiWindowType::DROID_DELETE_TRACK);
			box->setCallback(new DeleteTrackConfirmationSuiCallback(player->getZoneServer(), module, index));
			box->setPromptTitle("@pet/droid_modules:playback_delete_title"); // Delete Track
			box->setPromptText(prompt); // Are you sure you want to delete this track:
			box->setOkButton(true, "@ok");
			box->setCancelButton(true, "@cancel");
			box->setUsingObject(droid);
			player->getPlayerObject()->addSuiBox(box);
			player->sendMessage(box->generateMessage());
		} else {
			// if track is empty record
			if (trackPerformanceIndex == 0) {
				module->startRecordingSession(player, index);
			} else {
				module->playSong(player, trackPerformanceIndex);
			}
		}
	}
};

#endif /* DROIDPLAYBACKSUICALLBACK_H */
