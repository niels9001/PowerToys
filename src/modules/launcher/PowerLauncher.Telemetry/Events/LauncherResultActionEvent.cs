﻿// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using Microsoft.PowerToys.Telemetry;
using Microsoft.PowerToys.Telemetry.Events;
using System.Diagnostics.Tracing;

namespace Microsoft.PowerLauncher.Telemetry
{
    /// <summary>
    /// ETW event for when a result is actioned.
    /// </summary>
    [EventData]
    public class LauncherResultActionEvent : IEvent
    {

        public enum TriggerType
        {
            Click,
            KeyboardShortcut
        }

        public string Trigger { get; set; }
        public string PluginName { get; set; }
        public string ActionName { get; set; }

        public PartA_PrivTags PartA_PrivTags => PartA_PrivTags.ProductAndServiceUsage;
    }
}
