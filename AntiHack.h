
	namespace AntiHack
	{
		// Token: 0x04004C48 RID: 19528
		// // [Help("collider margin when checking for noclipping on dismount")]
		float noclip_margin_dismount = 0.22f;

		// Token: 0x04004C49 RID: 19529
		// // [Help("collider backtracking when checking for noclipping")]
		float noclip_backtracking = 0.01f;

		// Token: 0x04004C4A RID: 19530
		// // [Help("report violations to the anti cheat backend")]
		bool reporting = false;

		// Token: 0x04004C4B RID: 19531
		// [Help("are admins allowed to use their admin cheat")]
		// [ServerVar]
		bool admincheat = true;

		// Token: 0x04004C4C RID: 19532
		// [Help("use antihack to verify object placement by players")]
		// [ServerVar]
		bool objectplacement = true;

		// Token: 0x04004C4D RID: 19533
		// [ServerVar]
		// [Help("use antihack to verify model state sent by players")]
		bool modelstate = true;

		// Token: 0x04004C4E RID: 19534
		// [ServerVar]
		// [Help("whether or not to force the position on the client")]
		bool forceposition = true;

		// Token: 0x04004C4F RID: 19535
		// // [ServerVar]
		// // [Help("0 == users, 1 == admins, 2 == developers")]
		int userlevel = 2;

		// Token: 0x04004C50 RID: 19536
		// [ServerVar]
		// [Help("0 == no enforcement, 1 == kick, 2 == ban (DISABLED)")]
		int enforcementlevel = 1;

		// Token: 0x04004C51 RID: 19537
		// [Help("max allowed client desync, lower value = more false positives")]
		// [ServerVar]
		float maxdesync = 1.f;

		// Token: 0x04004C52 RID: 19538
		// [Help("max allowed client tick interval delta time, lower value = more false positives")]
		// [ServerVar]
		float maxdeltatime = 1.f;

		// Token: 0x04004C53 RID: 19539
		// [Help("for how many seconds to keep a tick history to use for distance checks")]
		// [ServerVar]
		float tickhistorytime = 0.5f;

		// Token: 0x04004C54 RID: 19540
		// [Help("how much forgiveness to add when checking the distance from the player tick history")]
		// [ServerVar]
		float tickhistoryforgiveness = 0.1f;

		// Token: 0x04004C55 RID: 19541
		// [ServerVar]
		// [Help("the rate at which violation values go back down")]
		float relaxationrate = 0.1f;

		// Token: 0x04004C56 RID: 19542
		// [Help("the time before violation values go back down")]
		// [ServerVar]
		float relaxationpause = 10.f;

		// Token: 0x04004C57 RID: 19543
		// [ServerVar]
		// [Help("violation value above this results in enforcement")]
		float maxviolation = 100.f;

		// Token: 0x04004C58 RID: 19544
		// [Help("0 == disabled, 1 == enabled")]
		// [ServerVar]
		int terrain_protection = 1;

		// Token: 0x04004C59 RID: 19545
		// [ServerVar]
		// [Help("how many slices to subdivide players into for the terrain check")]
		int terrain_timeslice = 64;

		// Token: 0x04004C5A RID: 19546
		// [Help("how far to penetrate the terrain before violating")]
		// [ServerVar]
		float terrain_padding = 0.3f;

		// Token: 0x04004C5B RID: 19547
		// [ServerVar]
		// [Help("violation penalty to hand out when terrain is detected")]
		float terrain_penalty = 100.f;

		// Token: 0x04004C5C RID: 19548
		// [ServerVar]
		// [Help("whether or not to kill the player when terrain is detected")]
		bool terrain_kill = true;

		// Token: 0x04004C5D RID: 19549
		// [ServerVar]
		// [Help("whether or not to check for player inside geometry like rocks as well as base terrain")]
		bool terrain_check_geometry = false;

		// Token: 0x04004C5E RID: 19550
		// [Help("0 == disabled, 1 == ray, 2 == sphere, 3 == curve")]
		// [ServerVar]
		int noclip_protection = 3;

		// Token: 0x04004C5F RID: 19551
		// [ServerVar]
		// [Help("whether or not to reject movement when noclip is detected")]
		bool noclip_reject = true;

		// Token: 0x04004C60 RID: 19552
		// [ServerVar]
		// [Help("violation penalty to hand out when noclip is detected")]
		float noclip_penalty = 0.f;

		// Token: 0x04004C61 RID: 19553
		// [ServerVar]
		// [Help("collider margin when checking for noclipping")]
		float noclip_margin = 0.09f;

		// Token: 0x04004C62 RID: 19554
		// [ServerVar]
		// [Help("movement curve step size, lower value = less false positives")]
		float noclip_stepsize = 0.1f;

		// Token: 0x04004C63 RID: 19555
		// [Help("movement curve max steps, lower value = more false positives")]
		// [ServerVar]
		int noclip_maxsteps = 15;

		// Token: 0x04004C64 RID: 19556
		// [Help("0 == disabled, 1 == simple, 2 == advanced")]
		// [ServerVar]
		int speedhack_protection = 2;

		// Token: 0x04004C65 RID: 19557
		// [ServerVar]
		// [Help("whether or not to reject movement when speedhack is detected")]
		bool speedhack_reject = true;

		// Token: 0x04004C66 RID: 19558
		// [Help("violation penalty to hand out when speedhack is detected")]
		// [ServerVar]
		float speedhack_penalty = 0.f;

		// Token: 0x04004C67 RID: 19559
		// [ServerVar]
		// [Help("speed threshold to assume speedhacking, lower value = more false positives")]
		float speedhack_forgiveness = 2.f;

		// Token: 0x04004C68 RID: 19560
		// [Help("speed threshold to assume speedhacking, lower value = more false positives")]
		// [ServerVar]
		float speedhack_forgiveness_inertia = 10.f;

		// Token: 0x04004C69 RID: 19561
		// [Help("speed forgiveness when moving down slopes, lower value = more false positives")]
		// [ServerVar]
		float speedhack_slopespeed = 10.f;

		// Token: 0x04004C6A RID: 19562
		// [Help("0 == disabled, 1 == client, 2 == capsule, 3 == curve")]
		// [ServerVar]
		int flyhack_protection = 3;

		// Token: 0x04004C6B RID: 19563
		// [ServerVar]
		// [Help("whether or not to reject movement when flyhack is detected")]
		bool flyhack_reject = false;

		// Token: 0x04004C6C RID: 19564
		// [ServerVar]
		// [Help("violation penalty to hand out when flyhack is detected")]
		float flyhack_penalty = 100.f;

		// Token: 0x04004C6D RID: 19565
		// [ServerVar]
		// [Help("distance threshold to assume flyhacking, lower value = more false positives")]
		float flyhack_forgiveness_vertical = 1.5f;

		// Token: 0x04004C6E RID: 19566
		// [ServerVar]
		// [Help("distance threshold to assume flyhacking, lower value = more false positives")]
		float flyhack_forgiveness_vertical_inertia = 10.f;

		// Token: 0x04004C6F RID: 19567
		// [ServerVar]
		// [Help("distance threshold to assume flyhacking, lower value = more false positives")]
		float flyhack_forgiveness_horizontal = 1.5f;

		// Token: 0x04004C70 RID: 19568
		// [ServerVar]
		// [Help("distance threshold to assume flyhacking, lower value = more false positives")]
		float flyhack_forgiveness_horizontal_inertia = 10.f;

		// Token: 0x04004C71 RID: 19569
		// [ServerVar]
		// [Help("collider downwards extrusion when checking for flyhacking")]
		float flyhack_extrusion = 2.f;

		// Token: 0x04004C72 RID: 19570
		// [ServerVar]
		// [Help("collider margin when checking for flyhacking")]
		float flyhack_margin = 0.05f;

		// Token: 0x04004C73 RID: 19571
		// [ServerVar]
		// [Help("movement curve step size, lower value = less false positives")]
		float flyhack_stepsize = 0.1f;

		// Token: 0x04004C74 RID: 19572
		// [Help("movement curve max steps, lower value = more false positives")]
		// [ServerVar]
		int flyhack_maxsteps = 15;

		// Token: 0x04004C75 RID: 19573
		// [ServerVar]
		// [Help("0 == disabled, 1 == speed, 2 == speed + entity, 3 == speed + entity + LOS, 4 == speed + entity + LOS + trajectory, 5 == speed + entity + LOS + trajectory + update, 6 == speed + entity + LOS + trajectory + tickhistory")]
		int projectile_protection = 6;

		// Token: 0x04004C76 RID: 19574
		// [Help("violation penalty to hand out when projectile hack is detected")]
		// [ServerVar]
		float projectile_penalty = 0.f;

		// Token: 0x04004C77 RID: 19575
		// [Help("projectile speed forgiveness in percent, lower value = more false positives")]
		// [ServerVar]
		float projectile_forgiveness = 0.5f;

		// Token: 0x04004C78 RID: 19576
		// [Help("projectile server frames to include in delay, lower value = more false positives")]
		// [ServerVar]
		float projectile_serverframes = 2.f;

		// Token: 0x04004C79 RID: 19577
		// [ServerVar]
		// [Help("projectile client frames to include in delay, lower value = more false positives")]
		float projectile_clientframes = 2.f;

		// Token: 0x04004C7A RID: 19578
		// [Help("projectile trajectory forgiveness, lower value = more false positives")]
		// [ServerVar]
		float projectile_trajectory = 1.f;

		// Token: 0x04004C7B RID: 19579
		// [Help("projectile penetration angle change, lower value = more false positives")]
		// [ServerVar]
		float projectile_anglechange = 60.f;

		// Token: 0x04004C7C RID: 19580
		// [ServerVar]
		// [Help("projectile penetration velocity change, lower value = more false positives")]
		float projectile_velocitychange = 1.1f;

		// Token: 0x04004C7D RID: 19581
		// [Help("projectile desync forgiveness, lower value = more false positives")]
		// [ServerVar]
		float projectile_desync = 1.f;

		// Token: 0x04004C7E RID: 19582
		// [Help("projectile backtracking when checking for LOS")]
		// [ServerVar]
		float projectile_backtracking = 0.01f;

		// Token: 0x04004C7F RID: 19583
		// [Help("line of sight directional forgiveness when checking eye or center position")]
		// [ServerVar]
		float projectile_losforgiveness = 0.2f;

		// Token: 0x04004C80 RID: 19584
		// [Help("how often a projectile is allowed to penetrate something before its damage is ignored")]
		// [ServerVar]
		int projectile_damagedepth = 2;

		// Token: 0x04004C81 RID: 19585
		// [ServerVar]
		// [Help("how often a projectile is allowed to penetrate something before its impact spawn is ignored")]
		int projectile_impactspawndepth = 1;

		// Token: 0x04004C82 RID: 19586
		// [ServerVar]
		// [Help("whether or not to include terrain in the projectile LOS checks")]
		bool projectile_terraincheck = true;

		// Token: 0x04004C83 RID: 19587
		// [ServerVar]
		// [Help("0 == disabled, 1 == initiator, 2 == initiator + target, 3 == initiator + target + LOS, 4 == initiator + target + LOS + tickhistory")]
		int melee_protection = 4;

		// Token: 0x04004C84 RID: 19588
		// [ServerVar]
		// [Help("violation penalty to hand out when melee hack is detected")]
		float melee_penalty = 0.f;

		// Token: 0x04004C85 RID: 19589
		// [ServerVar]
		// [Help("melee distance forgiveness in percent, lower value = more false positives")]
		float melee_forgiveness = 0.5f;

		// Token: 0x04004C86 RID: 19590
		// [ServerVar]
		// [Help("melee server frames to include in delay, lower value = more false positives")]
		float melee_serverframes = 2.f;

		// Token: 0x04004C87 RID: 19591
		// [ServerVar]
		// [Help("melee client frames to include in delay, lower value = more false positives")]
		float melee_clientframes = 2.f;

		// Token: 0x04004C88 RID: 19592
		// [ServerVar]
		// [Help("melee backtracking when checking for LOS")]
		float melee_backtracking = 0.01f;

		// Token: 0x04004C89 RID: 19593
		// [ServerVar]
		// [Help("line of sight directional forgiveness when checking eye or center position")]
		float melee_losforgiveness = 0.2f;

		// Token: 0x04004C8A RID: 19594
		// [ServerVar]
		// [Help("whether or not to include terrain in the melee LOS checks")]
		bool melee_terraincheck = true;

		// Token: 0x04004C8B RID: 19595
		// [ServerVar]
		// [Help("0 == disabled, 1 == distance, 2 == distance + LOS, 3 = distance + LOS + altitude, 4 = distance + LOS + altitude + noclip, 5 = distance + LOS + altitude + noclip + history")]
		int eye_protection = 4;

		// Token: 0x04004C8C RID: 19596
		// [ServerVar]
		// [Help("violation penalty to hand out when eye hack is detected")]
		float eye_penalty = 0.f;

		// Token: 0x04004C8D RID: 19597
		// [ServerVar]
		// [Help("eye speed forgiveness in percent, lower value = more false positives")]
		float eye_forgiveness = 0.5f;

		// Token: 0x04004C8E RID: 19598
		// [Help("eye server frames to include in delay, lower value = more false positives")]
		// [ServerVar]
		float eye_serverframes = 2.f;

		// Token: 0x04004C8F RID: 19599
		// [ServerVar]
		// [Help("eye client frames to include in delay, lower value = more false positives")]
		float eye_clientframes = 2.f;

		// Token: 0x04004C90 RID: 19600
		// [ServerVar]
		// [Help("whether or not to include terrain in the eye LOS checks")]
		bool eye_terraincheck = true;

		// Token: 0x04004C91 RID: 19601
		// [ServerVar]
		// [Help("distance at which to start testing eye noclipping")]
		float eye_noclip_cutoff = 0.06f;

		// Token: 0x04004C92 RID: 19602
		// [ServerVar]
		// [Help("collider margin when checking for noclipping")]
		float eye_noclip_margin = 0.21f;

		// Token: 0x04004C93 RID: 19603
		// [ServerVar]
		// [Help("collider backtracking when checking for noclipping")]
		float eye_noclip_backtracking = 0.01f;

		// Token: 0x04004C94 RID: 19604
		// [ServerVar]
		// [Help("line of sight sphere cast radius, 0 == raycast")]
		float eye_losradius = 0.18f;

		// Token: 0x04004C95 RID: 19605
		// [ServerVar]
		// [Help("violation penalty to hand out when eye history mismatch is detected")]
		float eye_history_penalty = 100.f;

		// Token: 0x04004C96 RID: 19606
		// [ServerVar]
		// [Help("how much forgiveness to add when checking the distance between player tick history and player eye history")]
		float eye_history_forgiveness = 0.1f;

		// Token: 0x04004C97 RID: 19607
		// [ServerVar]
		// [Help("line of sight sphere cast radius, 0 == raycast")]
		float build_losradius = 0.01f;

		// Token: 0x04004C98 RID: 19608
		// [ServerVar]
		// [Help("line of sight sphere cast radius, 0 == raycast")]
		float build_losradius_sleepingbag = 0.3f;

		// Token: 0x04004C99 RID: 19609
		// [ServerVar]
		// [Help("whether or not to include terrain in the build LOS checks")]
		bool build_terraincheck = true;

		// [Help("whether or not to check for building being done on the wrong side of something (e.g. inside rocks). 0 = Disabled, 1 = Info only, 2 = Enabled")]
		// [ServerVar]
		int build_inside_check = 2;

		// // [ServerVar]
		// // [Help("0 == silent, 1 == print max violation, 2 == print nonzero violation, 3 == print any violation except noclip, 4 == print any violation")]
		int debuglevel = 1;
	};
