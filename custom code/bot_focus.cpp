// Focus Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "focus")) && (c->IsGrouped())) {
		Mob *FocusCaster;
		uint32 FocusClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case SHAMAN:
							FocusCaster = g->members[i];
							FocusClass = SHAMAN;
							break;
						case PALADIN:
							if(FocusClass != SHAMAN){
								FocusCaster = g->members[i];
								FocusClass = BEASTLORD;
							}
							break;
						default:
							break;
					}
				}
			}
			switch(FocusClass) {
                                case SHAMAN:
                                        if (c->GetLevel() >= 60) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "Casting Focus of Spirit.");
                                                FocusCaster->CastToBot()->SpellOnTarget(1432, target);
                                        }
                                        else if (c->GetLevel() >= 55) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "Casting Talisman of Kragg.");
                                                FocusCaster->CastToBot()->SpellOnTarget(1585, target);
					}
                                        else if (c->GetLevel() >= 46) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "Casting Harnessing of Spirit.");
                                                FocusCaster->CastToBot()->SpellOnTarget(2525, target);
					}
                                        else if (c->GetLevel() >= 40) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "Casting Talisman of Altuna.");
                                                FocusCaster->CastToBot()->SpellOnTarget(168, target);
					}
                                        else if (c->GetLevel() >= 32) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "Casting Talisman of Tnarg.");
                                                FocusCaster->CastToBot()->SpellOnTarget(167, target);
					}
					else if (c->GetLevel() <= 31) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "I must reach level 32 before casting a focus buff.");
                                        }
					break;
						
				case BEASTLORD:
                                        if (c->GetLevel() >= 58) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "Casting Talisman of Altuna.");
                                                FocusCaster->CastToBot()->SpellOnTarget(168, target);
                                        }
                                        else if (c->GetLevel() >= 53) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "Casting Talisman of Tnarg.");
                                                FocusCaster->CastToBot()->SpellOnTarget(167, target);
                                        }
                                        else if (c->GetLevel() <= 52) {
                                                FocusCaster->CastToBot()->BotGroupSay(FocusCaster->CastToBot(), "I must reach level 53 before casting a focus buff.");
                                        }
                                        break;
                        }
		}
	}
