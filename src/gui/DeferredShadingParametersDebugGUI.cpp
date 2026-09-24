#include "DeferredShadingParametersDebugGUI.h"
#include "imgui.h"
#include "mc/client/dragon/framerenderer/DeferredShadingParameters.h"

static const char *DirectionalShadowsModeNames[] = {"Off", "Cascade", "Evsm"};

template <typename T>
bool ImGui_EnumCombo(const char *label, T *value, const char *const *items,
                     int count) {
  int v = int(*value);
  bool changed = ImGui::Combo(label, &v, items, count);
  if (changed)
    *value = static_cast<T>(v);
  return changed;
}

void DrawDeferredShadingParametersDebugWindow(
    dragon::framerenderer::DeferredShadingParameters *cfg, bool *p_open) {
  if (!cfg)
    return;
  if (!ImGui::Begin("Deferred Shading Parameters", p_open)) {
    ImGui::End();
    return;
  }

  ImGui::InputFloat3("Block Base Ambient Light Color",
                     cfg->mBlockBaseAmbientLightColor.data());
  ImGui::InputFloat("Block Light Indirect Contribution Multiplier",
                    &cfg->mBlockLightIndirectContributionMultiplier, 0.01f,
                    0.1f);
  ImGui::InputFloat("Block Light Indirect Specular Fallback Multiplier",
                    &cfg->mBlockLightIndirectSpecularFallbackMultiplier, 0.01f,
                    0.1f);
  ImGui::InputFloat("Sky Light Indirect Contribution Multiplier",
                    &cfg->mSkyLightIndirectContributionMultiplier, 0.01f, 0.1f);
  ImGui::InputFloat("IBL Indirect Contribution Multiplier",
                    &cfg->mIBLIndirectContributionMultiplier, 0.01f, 0.1f);
  ImGui::InputFloat("Volumetric Fog Min Ambient Value",
                    &cfg->mVolumetricFogMinAmbientValue, 0.01f, 0.1f);
  ImGui::InputInt("IBL SkyLight Fade Start", (int *)&cfg->mIBLSkyLightFadeStart,
                  1, 10);
  ImGui::InputInt("IBL SkyLight Fade End", (int *)&cfg->mIBLSkyLightFadeEnd, 1,
                  10);
  ImGui::InputFloat("Camera Light Intensity Lerp Speed",
                    &cfg->mCameraLightIntensityLerpSpeed, 0.01f, 0.1f);
  ImGui::InputFloat("Emissive Brightness Multiplier",
                    &cfg->mEmissiveBrightnessMultiplier, 0.01f, 0.1f);
  ImGui::InputInt("Emissive Brightness VLU Normalization Factor",
                  &cfg->mEmissiveBrightnessVLUNormalizationFactor, 1, 10);
  ImGui::InputFloat("Directional Light Contribution Fade End Angle",
                    &cfg->mDirectionalLightContributionFadeEndAngle, 0.01f,
                    0.1f);
  ImGui::InputFloat("Directional Light Contribution Fade Begin Angle",
                    &cfg->mDirectionalLightContributionFadeBeginAngle, 0.01f,
                    0.1f);
  ImGui::InputFloat(
      "Directional Light Contribution Fade End Angle Atmospherics",
      &cfg->mDirectionalLightContributionFadeEndAngleAtmospherics, 0.01f, 0.1f);
  ImGui::InputFloat(
      "Directional Light Contribution Fade Begin Angle Atmospherics",
      &cfg->mDirectionalLightContributionFadeBeginAngleAtmospherics, 0.01f,
      0.1f);
  ImGui::InputFloat("Subsurface Scattering Contribution",
                    &cfg->mSubsurfaceScatteringContribution, 0.01f, 0.1f);
  ImGui::InputFloat("Subsurface Scattering Diffuse Wrap Value",
                    &cfg->mSubsurfaceScatteringDiffuseWrapValue, 0.01f, 0.1f);
  ImGui::InputFloat("Subsurface Scattering Falloff Distance",
                    &cfg->mSubsurfaceScatteringFalloffDistance, 0.01f, 0.1f);
  ImGui::InputFloat("End Portal Emissive Multiplier",
                    &cfg->mEndPortalEmissiveMultiplier, 0.01f, 0.1f);
  ImGui::InputFloat("Sun Texture Emissive Multiplier",
                    &cfg->mSunTextureEmissiveMultiplier, 0.01f, 0.1f);
  ImGui::InputFloat("Moon Texture Emissive Multiplier",
                    &cfg->mMoonTextureEmissiveMultiplier, 0.01f, 0.1f);
  ImGui::InputFloat("Glow Ink Sign Strength", &cfg->mGlowInkSignStrength, 0.01f,
                    0.1f);
  ImGui::InputFloat("Lightning Bolt Adaptive Emissive Multiplier",
                    &cfg->mLightningBoltAdaptiveEmissiveMultiplier, 0.01f,
                    0.1f);

  ImGui_EnumCombo("Directional Shadows Mode", &cfg->mDirectionalShadowsMode,
                  DirectionalShadowsModeNames,
                  IM_ARRAYSIZE(DirectionalShadowsModeNames));

  ImGui::Checkbox("Specular Enabled", &cfg->mSpecularEnabled);
  ImGui::Checkbox("Diffuse Enabled", &cfg->mDiffuseEnabled);
  ImGui::Checkbox("Emissive Enabled", &cfg->mEmissiveEnabled);
  ImGui::Checkbox("Ambient Enabled", &cfg->mAmbientEnabled);
  ImGui::Checkbox("Directional Light Contribution Enabled",
                  &cfg->mDirectionalLightContributionEnabled);
  ImGui::Checkbox("Point Light Contribution Enabled",
                  &cfg->mPointLightContributionEnabled);
  ImGui::Checkbox("Enable Deferred Shading SkyLight Heuristic",
                  &cfg->mEnableDeferredShadingSkyLightHeuristic);
  ImGui::Checkbox("Enable Volumetric SkyLight Heuristic",
                  &cfg->mEnableVolumetricSkyLightHeuristic);

  ImGui::InputFloat3("Ambient Light Color", (float *)&cfg->mAmbientLightColor);
  ImGui::InputFloat("Ambient Light Illuminance", &cfg->mAmbientLightIlluminance,
                    0.01f, 0.1f);
  ImGui::InputFloat("Sky Intensity", &cfg->mSkyIntensity, 0.01f, 0.1f);

  ImGui::Checkbox("Texel Reflections Enabled", &cfg->mTexelReflectionsEnabled);
  ImGui::Checkbox("Texel Shadows Enabled", &cfg->mTexelShadowsEnabled);
  ImGui::Checkbox("Disable Shadow Filtering", &cfg->mDisableShadowFiltering);

  ImGui::InputInt("Quantized Texel Size", &cfg->mQuantizedTexelSize, 1, 10);
  ImGui::InputFloat("Quantization Surface Normal Precision",
                    &cfg->mQuantizationSurfaceNormalPrecision, 0.01f, 0.1f);

  ImGui::End();
}
