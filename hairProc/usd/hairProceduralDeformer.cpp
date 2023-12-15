#include "hairProceduralDeformer.h"
#include "tokens.h"

#include "pxr/imaging/hd/tokens.h"
#include "pxr/imaging/hd/meshSchema.h"
#include "pxr/imaging/hd/meshTopologySchema.h"
#include "pxr/imaging/hd/basisCurvesSchema.h"
#include "pxr/imaging/hd/primvarsSchema.h"
#include "pxr/imaging/hd/xformSchema.h"
#include "pxr/imaging/hd/basisCurvesTopologySchema.h"
#include "pxr/base/trace/trace.h"

#include "pxr/base/vt/value.h"
#include "pxr/base/gf/matrix4f.h"

#include <iostream>
#include <thread>
#include <numeric>


PXR_NAMESPACE_OPEN_SCOPE

HairProcHairProceduralDeformer::HairProcHairProceduralDeformer(
        VtArray<HdContainerDataSourceHandle> targetContainers,
        HdContainerDataSourceHandle sourceContainer,
        const SdfPath& primPath) : _targetContainers(targetContainers), _sourceContainer(sourceContainer), _primPath(primPath.GetAsString()) {
}

VtVec3fArray HairProcHairProceduralDeformer::Deform(const HdSampledDataSource::Time& shutterOffset) {
    auto srcPrimvarsSchema = HdPrimvarsSchema::GetFromParent(_sourceContainer);
    VtVec3fArray srcPos = srcPrimvarsSchema.GetPrimvar(HdTokens->points).GetPrimvarValue()->GetValue(0).UncheckedGet<VtArray<GfVec3f>>();
    return srcPos;
}

PXR_NAMESPACE_CLOSE_SCOPE