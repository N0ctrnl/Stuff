// Haste Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "hp1")) && (c->IsGrouped())) {
		Mob *HasteCaster;
		uint32 HasteClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case CLERIC:
							HasteCaster = g->members[i];
							HasteClass = CLERIC;
							break;
						case PALADIN:
							if(HasteClass != CLERIC){
								HasteCaster = g->members[i];
								HasteClass = PALADIN;
							}
							break;
					}
				}
			}
			switch(HasteClass) {
                                case ENCHANTER:
                                        if (c->GetLevel() >= 60) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Visions of Grandeur.");
                                                HasteCaster->CastToBot()->SpellOnTarget(1710, target);
                                        }
                                        else if (c->GetLevel() >= 58) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Wonderous Rapidity.");
                                                HasteCaster->CastToBot()->SpellOnTarget(1709, target);
					}
                                        else if (c->GetLevel() >= 56) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Augment.");
                                                HasteCaster->CastToBot()->SpellOnTarget(1729, target);
					}
                                        else if (c->GetLevel() >= 53) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Aanya's Quickening.");
                                                HasteCaster->CastToBot()->SpellOnTarget(1708, target);
					}
                                        else if (c->GetLevel() >= 47) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Swift Like the Wind.");
                                                HasteCaster->CastToBot()->SpellOnTarget(172, target);
					}
					else if (c->GetLevel() >= 39) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Celerity.");
                                                HasteCaster->CastToBot()->SpellOnTarget(171, target);
					}
					else if (c->GetLevel() >= 28) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Augmentation.");
                                                HasteCaster->CastToBot()->SpellOnTarget(10, target);
					}
					else if (c->GetLevel() >= 21) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Alacrity.");
                                                HasteCaster->CastToBot()->SpellOnTarget(170, target);
					}
					else if (c->GetLevel() >= 15) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Quickness.");
                                                HasteCaster->CastToBot()->SpellOnTarget(39, target);
					}
					else if (c->GetLevel() <= 14) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "I must reach level 15 before casting a haste buff.");
                                        }
					break;
						
				case SHAMAN:
                                        if (c->GetLevel() >= 56) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Celerity.");
                                                HasteCaster->CastToBot()->SpellOnTarget(171, target);
                                        }
                                        else if (c->GetLevel() >= 42) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Alacrity.");
                                                HasteCaster->CastToBot()->SpellOnTarget(170, target);
                                        }
                                        else if (c->GetLevel() >= 26) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Quickness.");
                                                HasteCaster->CastToBot()->SpellOnTarget(39, target);
                                        }
                                        else if (c->GetLevel() <= 25) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "I must reach level 26 before casting a haste buff.");
                                        }
                                        break;
				case BEASTLORD:
					if (c->GetLevel() >= 60) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "Casting Alacrity.");
                                                HasteCaster->CastToBot()->SpellOnTarget(170, target);
                                        }
                                        else if (c->GetLevel() <= 59) {
                                                HasteCaster->CastToBot()->BotGroupSay(HasteCaster->CastToBot(), "I must reach level 60 before casting a haste buff.");
                                        }
                        }
		}
	}
