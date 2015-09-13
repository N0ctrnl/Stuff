// Skin Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "buff") && !strcasecmp(sep->arg[2], "skin")) && (c->IsGrouped())) {
		Mob *SkinCaster;
		uint32 SkinClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case DRUID:
							SkinCaster = g->members[i];
							SkinClass = DRUID;
							break;
						case RANGER:
							if(SkinClass != DRUID){
								SkinCaster = g->members[i];
								SkinClass = RANGER;
							}
							break;
					default:
						break;
					}
				}
			}
			switch(SkinClass) {
                                case DRUID:
                                        if (c->GetLevel() >= 60) { SkinCaster->CastToBot()->SpellOnTarget(1442, target); }
                                        else if (c->GetLevel() >= 57) { SkinCaster->CastToBot()->SpellOnTarget(1559, target); }
                                        else if (c->GetLevel() >= 46) { SkinCaster->CastToBot()->SpellOnTarget(423, target); }
                                        else if (c->GetLevel() >= 36) { SkinCaster->CastToBot()->SpellOnTarget(422, target); }
                                        else if (c->GetLevel() >= 24) { SkinCaster->CastToBot()->SpellOnTarget(421, target); }
                                        else if (c->GetLevel() >= 14) { SkinCaster->CastToBot()->SpellOnTarget(263, target); }
                                        else if (c->GetLevel() >= 1) { SkinCaster->CastToBot()->SpellOnTarget(26, target); }
					break;
						
				case RANGER:
                                        if (c->GetLevel() >= 59) { SkinCaster->CastToBot()->SpellOnTarget(423, target); }
                                        else if (c->GetLevel() >= 54) { SkinCaster->CastToBot()->SpellOnTarget(422, target); }
                                        else if (c->GetLevel() >= 38) { SkinCaster->CastToBot()->SpellOnTarget(421, target); }
                                        else if (c->GetLevel() >= 21) { SkinCaster->CastToBot()->SpellOnTarget(263, target); }
                                        else if (c->GetLevel() >= 7) { SkinCaster->CastToBot()->SpellOnTarget(26, target); }
					else if (c->GetLevel() <= 6) { SkinCaster->CastToBot()->BotGroupSay(SkinCaster->CastToBot(), "I must reach level 6 before casting a strength buff."); }
                                        break;
                        }
		}
	}

