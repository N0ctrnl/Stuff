CREATE TABLE `bots` (
        `BotID` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
        `BotOwnerCharacterID` INT(10) UNSIGNED NOT NULL,
        `BotSpellsID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `Name` VARCHAR(64) NOT NULL,
        `LastName` VARCHAR(32) DEFAULT NULL,
        `BotLevel` TINYINT(2) UNSIGNED NOT NULL DEFAULT '0',
        `Race` SMALLINT(5) NOT NULL DEFAULT '0',
        `Class` TINYINT(2) NOT NULL DEFAULT '0',
        `Gender` TINYINT(2) NOT NULL DEFAULT '0',
        `Size` FLOAT NOT NULL DEFAULT '0',
        `Face` INT(10) NOT NULL DEFAULT '1',
        `LuclinHairStyle` INT(10) NOT NULL DEFAULT '1',
        `LuclinHairColor` INT(10) NOT NULL DEFAULT '1',
        `LuclinEyeColor` INT(10) NOT NULL DEFAULT '1',
        `LuclinEyeColor2` INT(10) NOT NULL DEFAULT '1',
        `LuclinBeardColor` INT(10) NOT NULL DEFAULT '1',
        `LuclinBeard` INT(10) NOT NULL DEFAULT '0',
        `DrakkinHeritage` INT(10) NOT NULL DEFAULT '0',
        `DrakkinTattoo` INT(10) NOT NULL DEFAULT '0',
        `DrakkinDetails` INT(10) NOT NULL DEFAULT '0',
        `HP` INTEGER NOT NULL DEFAULT '0',
        `Mana` INTEGER NOT NULL DEFAULT '0',
        `MR` SMALLINT(5) NOT NULL DEFAULT '0',
        `CR` SMALLINT(5) NOT NULL DEFAULT '0',
        `DR` SMALLINT(5) NOT NULL DEFAULT '0',
        `FR` SMALLINT(5) NOT NULL DEFAULT '0',
        `PR` SMALLINT(5) NOT NULL DEFAULT '0',
        `Corrup` SMALLINT(5) NOT NULL DEFAULT '0',
        `AC` SMALLINT(5) NOT NULL DEFAULT '0',
        `STR` MEDIUMINT(8) NOT NULL DEFAULT '75',
        `STA` MEDIUMINT(8) NOT NULL DEFAULT '75',
        `DEX` MEDIUMINT(8) NOT NULL DEFAULT '75',
        `AGI` MEDIUMINT(8) NOT NULL DEFAULT '75',
        `_INT` MEDIUMINT(8) NOT NULL DEFAULT '80',
        `WIS` MEDIUMINT(8) NOT NULL DEFAULT '75',
        `CHA` MEDIUMINT(8) NOT NULL DEFAULT '75',
        `ATK` MEDIUMINT(9) NOT NULL DEFAULT '0',
        `BotCreateDate` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
        `LastSpawnDate` DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00',
        `TotalPlayTime` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `LastZoneId` SMALLINT(6) NOT NULL DEFAULT '0',
        `BotInspectMessage` VARCHAR(256) NOT NULL DEFAULT '',
        PRIMARY KEY (`BotID`)
) ENGINE=InnoDB;

CREATE TABLE `botstances` (
        `BotID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `StanceID` TINYINT UNSIGNED NOT NULL DEFAULT '0',
        PRIMARY KEY (`BotID`),
        CONSTRAINT `FK_botstances_1` FOREIGN KEY (`BotID`) REFERENCES `bots` (`BotID`)
);

CREATE TABLE `bottimers` (
        `BotID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `TimerID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `Value` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        PRIMARY KEY (`BotID`),
        CONSTRAINT `FK_bottimers_1` FOREIGN KEY (`BotID`) REFERENCES `bots` (`BotID`)
);

CREATE TABLE `botbuffs` (
        `BotBuffId` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
        `BotId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `SpellId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `CasterLevel` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `DurationFormula` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `TicsRemaining` INT(11) UNSIGNED NOT NULL DEFAULT '0',
        `PoisonCounters` INT(11) UNSIGNED NOT NULL DEFAULT '0',
        `DiseaseCounters` INT(11) UNSIGNED NOT NULL DEFAULT '0',
        `CurseCounters` INT(11) UNSIGNED NOT NULL DEFAULT '0',
        `CorruptionCounters` INT(11) UNSIGNED NOT NULL DEFAULT '0',
        `HitCount` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `MeleeRune` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `MagicRune` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `DeathSaveSuccessChance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `CasterAARank` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `Persistent` TINYINT(1) NOT NULL DEFAULT '0',
        PRIMARY KEY (`BotBuffId`),
        KEY `FK_botbuff_1` (`BotId`),
        CONSTRAINT `FK_botbuff_1` FOREIGN KEY (`BotId`) REFERENCES `bots` (`BotID`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=latin1;

CREATE TABLE `botinventory` (
        `BotInventoryID` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
        `BotID` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        `SlotID` INTEGER SIGNED NOT NULL DEFAULT '0',
        `ItemID` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        `charges` TINYINT(3) UNSIGNED DEFAULT 0,
        `color` INTEGER UNSIGNED NOT NULL DEFAULT 0,
        `augslot1` MEDIUMINT(7) UNSIGNED NOT NULL DEFAULT 0,
        `augslot2` MEDIUMINT(7) UNSIGNED NOT NULL DEFAULT 0,
        `augslot3` MEDIUMINT(7) UNSIGNED NOT NULL DEFAULT 0,
        `augslot4` MEDIUMINT(7) UNSIGNED NOT NULL DEFAULT 0,
        `augslot5` MEDIUMINT(7) UNSIGNED DEFAULT 0,
        `instnodrop` TINYINT(1) UNSIGNED NOT NULL DEFAULT 0,
        PRIMARY KEY (`BotInventoryID`),
        KEY `FK_botinventory_1` (`BotID`),
        CONSTRAINT `FK_botinventory_1` FOREIGN KEY (`BotID`) REFERENCES `bots` (`BotID`)
) ENGINE=InnoDB;

CREATE TABLE `botpets` (
        `BotPetsId` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
        `PetId` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        `BotId` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        `Name` VARCHAR(64) NULL,
        `Mana` INTEGER NOT NULL DEFAULT '0',
        `HitPoints` INTEGER NOT NULL DEFAULT '0',
        PRIMARY KEY (`BotPetsId`),
        KEY `FK_botpets_1` (`BotId`),
        CONSTRAINT `FK_botpets_1` FOREIGN KEY (`BotId`) REFERENCES `bots` (`BotID`),
        CONSTRAINT `U_botpets_1` UNIQUE (`BotId`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=latin1;

CREATE TABLE `botpetbuffs` (
        `BotPetBuffId` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
        `BotPetsId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `SpellId` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `CasterLevel` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `Duration` INT(11) UNSIGNED NOT NULL DEFAULT '0',
        PRIMARY KEY (`BotPetBuffId`),
        KEY `FK_botpetbuffs_1` (`BotPetsId`),
        CONSTRAINT `FK_botpetbuffs_1` FOREIGN KEY (`BotPetsId`) REFERENCES `botpets` (`BotPetsID`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=latin1;

CREATE TABLE `botpetinventory` (
        `BotPetInventoryId` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
        `BotPetsId` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        `ItemId` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        PRIMARY KEY (`BotPetInventoryId`),
        KEY `FK_botpetinventory_1` (`BotPetsId`),
        CONSTRAINT `FK_botpetinventory_1` FOREIGN KEY (`BotPetsId`) REFERENCES `botpets` (`BotPetsID`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=latin1;

CREATE TABLE `botgroup` (
        `BotGroupId` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
        `BotGroupLeaderBotId` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        `BotGroupName` VARCHAR(64) NOT NULL,
        PRIMARY KEY  (`BotGroupId`),
        KEY `FK_botgroup_1` (`BotGroupLeaderBotId`),
        CONSTRAINT `FK_botgroup_1` FOREIGN KEY (`BotGroupLeaderBotId`) REFERENCES `bots` (`BotID`)
) ENGINE=InnoDB;

CREATE TABLE `botgroupmembers` (
        `BotGroupMemberId` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
        `BotGroupId` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        `BotId` INTEGER UNSIGNED NOT NULL DEFAULT '0',
        PRIMARY KEY  (`BotGroupMemberId`),
        KEY `FK_botgroupmembers_1` (`BotGroupId`),
        CONSTRAINT `FK_botgroupmembers_1` FOREIGN KEY (`BotGroupId`) REFERENCES `botgroup` (`BotGroupId`),
        KEY `FK_botgroupmembers_2` (`BotId`),
        CONSTRAINT `FK_botgroupmembers_2` FOREIGN KEY (`BotId`) REFERENCES `bots` (`BotID`)
) ENGINE=InnoDB;

CREATE TABLE `botguildmembers` (
        `char_id` INT(11) NOT NULL DEFAULT '0',
        `guild_id` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
        `rank` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
        `tribute_enable` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
        `total_tribute` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `last_tribute` INT(10) UNSIGNED NOT NULL DEFAULT '0',
        `banker` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
        `public_note` TEXT NULL,
        `alt` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
        PRIMARY KEY  (`char_id`)
) ENGINE=InnoDB;

