// Copyright Cirquitry

using UnrealBuildTool;
using System.Collections.Generic;

public class Cirquitry_ProjectTarget : TargetRules
{
	public Cirquitry_ProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Cirquitry_Project" } );
	}
}
