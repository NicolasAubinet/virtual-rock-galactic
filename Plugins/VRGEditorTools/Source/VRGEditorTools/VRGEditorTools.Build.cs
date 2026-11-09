using UnrealBuildTool;

public class VRGEditorTools : ModuleRules
{
	public VRGEditorTools(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
		PrivateDependencyModuleNames.AddRange(new string[] {
			"UnrealEd", "BlueprintGraph", "Kismet", "KismetCompiler", "AssetRegistry", "GraphEditor", "Json", "Slate", "SlateCore", "UMG", "UMGEditor"
		});
	}
}
