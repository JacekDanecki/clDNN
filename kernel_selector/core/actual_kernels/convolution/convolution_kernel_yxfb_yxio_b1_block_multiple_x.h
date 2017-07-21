﻿/*
// Copyright (c) 2016 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#pragma once

#include "convolution_kernel_base.h"

namespace KernelSelector {

    class ConvolutionKernel_yxfb_yxio_b1_block_mulitple_x : public ConvolutionKernelBase
    {
    public:
        ConvolutionKernel_yxfb_yxio_b1_block_mulitple_x() : ConvolutionKernelBase("convolution_gpu_yxfb_yxio_b1_block_multiple_x_fp32") {}
        virtual ~ConvolutionKernel_yxfb_yxio_b1_block_mulitple_x() {}

        virtual KernelsData GetKernelsData(const Params& params, const OptionalParams& options) const override;
        virtual ParamsKey GetSupportedKey() const override;
    
    protected:
        std::vector<WeightsLayout> GetSupportedWeightLayouts() const override { return{ WeightsLayout::yxio }; }
        bool Validate(const Params& p, const OptionalParams& o) const override;
        JitConstants GetJitConstants(const ConvolutionParams& params, DispatchData kd) const override;
        DispatchData SetDefault(const ConvolutionParams& arg) const override;
    };
}