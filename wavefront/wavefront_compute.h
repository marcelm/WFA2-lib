/*
 *                             The MIT License
 *
 * Wavefront Alignments Algorithms
 * Copyright (c) 2017 by Santiago Marco-Sola  <santiagomsola@gmail.com>
 *
 * This file is part of Wavefront Alignments Algorithms.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * PROJECT: Wavefront Alignments Algorithms
 * AUTHOR(S): Santiago Marco-Sola <santiagomsola@gmail.com>
 * DESCRIPTION: WaveFront alignment module for computing wavefronts
 */

#ifndef WAVEFRONT_COMPUTE_H_
#define WAVEFRONT_COMPUTE_H_

#include "wavefront_aligner.h"

/*
 * Compute limits
 */
void wavefront_compute_limits(
    wavefront_aligner_t* const wf_aligner,
    const wavefront_set_t* const wavefront_set,
    int* const lo,
    int* const hi);

/*
 * Input wavefronts (fetch)
 */
void wavefront_compute_fetch_input(
    wavefront_aligner_t* const wf_aligner,
    wavefront_set_t* const wavefront_set,
    const int score);

/*
 * Output wavefronts (allocate)
 */
void wavefront_compute_allocate_output_null(
    wavefront_aligner_t* const wf_aligner,
    int score);
void wavefront_compute_allocate_output(
    wavefront_aligner_t* const wf_aligner,
    wavefront_set_t* const wavefront_set,
    int score,
    const int lo,
    const int hi);

/*
 * Initialize wavefronts ends
 */
void wavefront_compute_init_ends(
    wavefront_aligner_t* const wf_aligner,
    wavefront_set_t* const wavefront_set,
    const int lo,
    const int hi);

/*
 * Trim wavefronts ends
 */
void wavefront_compute_trim_ends(
    wavefront_aligner_t* const wf_aligner,
    wavefront_t* const wavefront);
void wavefront_compute_trim_ends_set(
    wavefront_aligner_t* const wf_aligner,
    wavefront_set_t* const wavefront_set);


/*
 * Backtrace offloading (gap-linear)
 */
int wavefront_compute_offload_backtrace_blocks_linear(
    wavefront_aligner_t* const wf_aligner,
    wf_offset_t* const out_offsets,
    pcigar_t* const out_bt_pcigar,
    bt_block_idx_t* const out_bt_prev,
    const int lo,
    const int hi);
void wavefront_compute_offload_backtrace_linear(
    wavefront_aligner_t* const wf_aligner,
    const wavefront_set_t* const wavefront_set,
    const int lo,
    const int hi);

/*
 * Backtrace offloading (gap-affine)
 */
int wavefront_compute_offload_backtrace_blocks_affine(
    wavefront_aligner_t* const wf_aligner,
    wf_offset_t* const out_offsets,
    pcigar_t* const out_bt_pcigar,
    bt_block_idx_t* const out_bt_prev,
    const int lo,
    const int hi);
void wavefront_compute_offload_backtrace_affine(
    wavefront_aligner_t* const wf_aligner,
    const wavefront_set_t* const wavefront_set,
    const int lo,
    const int hi);

#endif /* WAVEFRONT_COMPUTE_H_ */
