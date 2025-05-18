// Copyright Cirquitry

using UnrealBuildTool;
using System.Collections.Generic;

public class Cirquitry_ProjectEditorTarget : TargetRules
{
	public Cirquitry_ProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Cirquitry_Project" } );
	}
}
